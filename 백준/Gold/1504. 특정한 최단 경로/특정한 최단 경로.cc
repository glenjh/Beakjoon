#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 801

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, e;
vector<pair<int, int>> v[MAX];
int dist[MAX];

void Dijkstra(int x){
    for(int i = 1 ; i <= n ; i++){
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i].first;
            int nCost = v[curr][i].second;
            if (dist[next] > cost + nCost){
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    FastIO();

    bool flag = true;
    int answer = 0, answer2 = 0;
    int must1, must2;
    cin >> n >> e;

    for(int i = 1 ; i <= n ; i++){
        dist[i] = INT_MAX;
    }

    for(int i = 0 ; i < e ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> must1 >> must2;

    Dijkstra(1);
    if(dist[must1] == INT_MAX){
        flag = false;
    }
    answer += dist[must1];
    answer2 += dist[must2];

    Dijkstra(must1);
    if (dist[must2] == INT_MAX){
        flag = false;
    }
    answer += dist[must2];
    answer2 += dist[n];

    Dijkstra(must2);
    if (dist[n] == INT_MAX){
        flag = false;
    }
    answer += dist[n];
    answer2 += dist[must1];

    if(!flag){
        cout << -1 << '\n';
    }else{
        cout << min(answer, answer2) << '\n';
    }
    
    return 0;
}