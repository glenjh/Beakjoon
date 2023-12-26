#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 101

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int item[MAX];
int dist[MAX];
int n, m, r, answer;
vector<pair<int, int>> v[MAX];

void Reset(){
    for(int i = 0 ; i < MAX ; i++){
        dist[i] = INT_MAX;
    }
}

int Dijkstra(int x){
    priority_queue<pair<int, int>> pq;
    dist[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i].first;
            int nCost = v[curr][i].second;
            if(dist[next] > cost + nCost){
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
    
    int rel = 0;
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] <= m){
            rel += item[i];
        }
    }

    return rel;
}

int main() {
    FastIO();
    
    cin >> n >> m >> r;
    for(int i = 1 ; i <= n ; i++){
        cin >> item[i];
        dist[i] = INT_MAX;
    }

    for(int i = 0 ; i < r ; i++){
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }

    for(int i = 1 ; i <= n ; i++){
        answer = max(Dijkstra(i), answer); 
        Reset();
    }

    cout << answer << '\n';

    return 0;
}