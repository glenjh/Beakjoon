#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int p[50001];
bool visited[50001];
vector<int> ans;
vector<int> v[50001];

void LCA(int u, int v){
    for(int i = 1 ; i <= n ; i++){
        visited[i] = false;
    }

    while(p[u] != u){
        visited[u] = true;
        u = p[u];
    }

    while(true){
        if(visited[v]){
            ans.push_back(v);
            break;
        }
        visited[v] = true;
        v = p[v];
    }
}

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            p[next] = x;
            DFS(next);
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
    }
    
    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);
    
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        LCA(u, v);
    }

    for(auto it : ans){
        cout << it << '\n';
    }

    return 0;
}