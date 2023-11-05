#include <iostream>
#include <vector>
#include <queue>
# define inf 100000000

using namespace std;

int v, e, start;
vector<pair<int,int>> my_vec[20001];
int dist[20001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int curr = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        for(int i = 0 ; i < my_vec[curr].size() ; i++){
            int cost = d + my_vec[curr][i].second;
            if(cost < dist[my_vec[curr][i].first]){
                dist[my_vec[curr][i].first] = cost;
                pq.push({-cost ,my_vec[curr][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    cin >> start;

    for(int i = 0 ; i < e ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        my_vec[u].push_back({v, w});
    }

    for(int i = 0 ; i < 20001 ; i++){
        dist[i] = inf;
    }

    dijkstra(start);

    for(int i = 1 ; i <= v ; i++){
        if(dist[i] == inf){ cout << "INF" << '\n'; }
        else{ cout << dist[i] << '\n'; }
    }
    return 0;
}