#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, r;
vector<int> v[100001];
int dep[100001];

bool visited[100001];

bool comp(int a, int b){
    return a > b;
}

void DFS(int x, int cnt){
    if(visited[x]){ return; }
    visited[x] = true;

    dep[x] = cnt;

    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            DFS(nx, cnt + 1);
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m >> r;
    for(int i = 1 ; i <= n ; i++){
        dep[i] = -1;
    }

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin(), v[i].end(), comp);
    }

    DFS(r, 0);

    for(int i = 1 ; i <= n ; i++){
        cout << dep[i] << '\n';
    }

    return 0;
}