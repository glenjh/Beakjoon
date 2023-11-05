#include <iostream>
#include <queue>
#include <vector>
#define inf 100000000

using namespace std;

vector<pair<int, int>> v[50001];
int dist[50001];
int n, m;

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

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int start, end, len;
        cin >> start >> end >> len;
        v[start].push_back({end, len});
        v[end].push_back({start, len});
    }

    for(int i = 0 ; i < 50001 ; i++){
        dist[i] = inf;
    }

    dijkstra(1);
    cout << dist[n] << '\n';

    return 0;
}