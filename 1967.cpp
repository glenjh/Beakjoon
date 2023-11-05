#include <iostream>
#include <vector>

using namespace std;

int n, maxDist = 0, maxNode = 0;
vector<pair<int, int>> v[10001];

bool visited[10001];

void reset(){
    for(int i = 0 ; i < 10001 ; i++){
        visited[i] = false;
    }
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int x, int cnt){
    if(visited[x]){ return; }
    visited[x] = true;

    if(cnt >= maxDist){
        maxDist = cnt;
        maxNode = x;
    }

    for(int i = 0 ; i < v[x].size() ; i++){
        int nextNode = v[x][i].first;
        int dist = v[x][i].second;
        if(!visited[nextNode]){
            int nextDist = cnt + dist;
            DFS(nextNode, nextDist);
        }
    }
}

int main(){
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n-1 ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    DFS(1, 0);

    maxDist = 0;
    reset();

    DFS(maxNode, 0);
    cout << maxDist << '\n';

    return 0;
}