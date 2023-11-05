#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100001];
int n, m, r;
int visited[1000001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int x, int cnt){
    visited[x] = cnt;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(visited[next] == -1){
            DFS(next, cnt + 1);
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m >> r;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin(), v[i].end());
        visited[i] = -1;
    }

    DFS(r, 0);
    for(int i = 1 ; i <= n ; i++){
        cout << visited[i] << '\n';
    }

    return 0;
}