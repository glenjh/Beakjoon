#include <iostream>
#include <vector>
#include <queue>
#define inf 100000000

using namespace std;

int n, m, x, M = 0;
vector<pair<int, int>> v[1001];
int dist[1001];
int temp[1001];

void reset(){
    for(int i = 0 ; i < 1001 ; i++){
        dist[i] = inf;
    }
}

void dijkstra(int x){
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if(dist[curr] < d){ continue; }

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

    cin >> n >> m >> x;
    for(int i = 0 ; i < m ; i++){
        int start, end, len;
        cin >> start >> end >> len;
        v[start].push_back({end, len});
    }

    for(int i = 0 ; i < 1001 ; i ++){
        dist[i] = inf;
    }

    for(int i = 1 ; i <= n ; i++){
        dijkstra(i);
        temp[i] = dist[x];
        reset();
    }

    dijkstra(x);
    for(int i = 1 ; i <= n ; i++){
        temp[i] += dist[i];
    }

    for(int i = 1 ; i <= n ; i++){
        if(temp[i] > M){
            M = temp[i];
        }
    }
    cout << M << '\n';
    return 0;
}