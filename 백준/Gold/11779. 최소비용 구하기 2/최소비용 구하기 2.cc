#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dist[MAX], route[MAX];

int main() {
    FastIO();

    int n, m;
    cin >> n;
    vector<int> rel;
    vector< pair<int, int> > v[MAX];

    for(int i = 1 ; i <= n ; i++){
        dist[i] = INT_MAX;
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;

    priority_queue< pair<int, int> > pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost > dist[curr]){ continue; }

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i].first;
            int nextCost = v[curr][i].second;

            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                route[next] = curr;
                pq.push({-dist[next], next});
            }
        }
    }

    cout << dist[end] << '\n';

    int idx = end;
    while(idx){
        rel.push_back(idx);
        idx = route[idx];
    }
    cout << rel.size() << '\n';
    for(int i = rel.size() - 1 ; i >= 0 ; i--){
        cout << rel[i] << ' ';
    }
    cout << '\n';

    return 0;
}