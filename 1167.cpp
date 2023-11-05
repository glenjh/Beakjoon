#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> vec[100001];
int v, maxNode, maxDist, rootNode;

bool visited[100001];

void reset(){
    for(int i = 0 ; i < 100001 ; i++){
        visited[i] = false;
    }
}

void DFS(int node, int dist){
    if(visited[node]){ return; }
    visited[node] = true;

    if(dist >= maxDist){
        maxDist = dist;
        maxNode = node;
    }

    for(int i = 0 ; i < vec[node].size() ; i++){
        int nextNode = vec[node][i].first;
        int nextDist = dist + vec[node][i].second;
        if(!visited[nextNode]){
            DFS(nextNode, nextDist);
        }
    }
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    cin >> v;
    for(int i = 0 ; i < v ; i++){
        int a;
        cin >> a;
        int b, dist;
        while(true){
            cin >> b;
            if(b == -1){ break; }
            cin >> dist;
            vec[a].push_back({b, dist});
            vec[b].push_back({a, dist}); 
        }
    }

    DFS(1, 0);

    maxDist = 0;

    reset();

    DFS(maxNode, 0);

    cout << maxDist << '\n';

    return 0;
}