#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, cnt = 1;
vector<pair<int, int>> ans;
vector<int> v[10001];

bool visited[10001];

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    cnt++;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            DFS(next);
        }
    }
}

void reset(){
    cnt = 1;
    for(int i = 0 ; i < 10001 ; i++){
        visited[i] = false;
    }
}

int main(){
    FastIO();
    
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        DFS(i);
        ans.push_back({i, cnt});
        reset();
    }

    int M = 0;
    for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i].second >= M){
            M = ans[i].second;
        }
    }

    for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i].second == M){
            cout << ans[i].first << ' ';
        }
    }

    return 0;
}