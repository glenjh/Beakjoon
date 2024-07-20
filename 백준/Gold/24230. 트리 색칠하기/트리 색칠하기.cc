#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int ans;
vector<int> v[200001];
int color[200001];
bool visited[200001];

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            if(color[x] != color[nx]){
                ans += 1;
            }
            DFS(nx);
        }
    }
}

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> color[i];
    }

    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if(color[1] != 0){
        ans += 1;
    }
    DFS(1);

    cout << ans << '\n';

    return 0;
}