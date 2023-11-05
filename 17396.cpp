#include <iostream>
#include <vector>
#include <queue>
#define inf 10000000000000

using namespace std;

int n, m;
vector<pair<long long, int>> v[100001];
vector<int> sight;
long long dist[100001];

void dijkstar(){
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        long long d = -pq.top().first;
        pq.pop();

        if(dist[curr] < d){ continue; }

        for(int i = 0 ; i < v[curr].size() ; i++){
            long long cost = d + v[curr][i].second;
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
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input; 
        sight.push_back(input);
    }

    for(int i = 0 ; i < m ; i++){
        long long a, b, t;
        cin >> a >> b >> t;
        if((sight[a] == 0 && sight[b] == 0) || (a == n-1 || b == n-1)){
            v[a].push_back({b, t});
            v[b].push_back({a, t});
        }
    }

    for(int i = 0 ; i < 100001 ; i++){
        dist[i] = inf;
    }

    dijkstar();

    if(dist[n-1] == inf){cout << -1 << '\n'; }
    else{ cout << dist[n-1] << '\n'; }

    return 0;
}