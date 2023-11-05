#include <iostream>
#include <vector>
#include <queue>
#define inf 100000000

using namespace std;

int n, m, s ,t;
vector<pair<int, int>> v[5001];
int dist[5001];

void dijkstra(int x){
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int cost = d + v[curr][i].second;
            if(cost < dist[ v[curr][i].first ]){
                dist[ v[curr][i].first ] = cost;
                pq.push({-cost, v[curr][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0 ; i < 5001 ; i++){
        dist[i] = inf;
    }
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> s >> t;
    dijkstra(s);

    cout << dist[t] << '\n';

    return 0;
}