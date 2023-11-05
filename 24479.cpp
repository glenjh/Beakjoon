#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, level = 1;

vector<int> v[100001];
int visited[100001];

int cnt[100001] = {0, };

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    cnt[x] += level++;

    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(!visited[child]){
            DFS(child);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> r;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }
    
    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin() , v[i].end());
    }

    DFS(r);

    for(int i = 1 ; i <= n ; i++){
        cout << cnt[i] << '\n';
    }
    return 0;
}