#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, d;
vector<pair<int, int>> v[10001];
int dist[10001];

int main() {
    FastIO();

    for(int i = 0 ; i < 10001 ; i++){
        dist[i] = INF;
    }

    cin >> n >> d;
    for(int i = 0 ; i < n ; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        if(d >= end){
            v[end].push_back({start, cost});
        }
    }
    
    dist[0] = 0;
    for(int i = 1 ; i <= d ; i++){
        if(v[i].size() == 0){
            dist[i] = dist[i - 1] + 1;
        }
        else{
            for(int j = 0 ; j < v[i].size() ; j++){
                dist[i] = min({dist[i], dist[i - 1] + 1, dist[v[i][j].first] + v[i][j].second});
            }
        }
    }

    cout << dist[d] << '\n';

    return 0;
}