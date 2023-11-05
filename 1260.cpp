#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> arr [1001];

bool visited[1001];

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    cout << x << ' ';

    for(int i = 0 ; i < arr[x].size() ; i++){
        int sibling = arr[x][i];
        if(!visited[sibling]){
            DFS(sibling);
        }
    }
}

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout << parent << " ";

        for(int i = 0 ; i < arr[parent].size() ; i++){
            int sibling = arr[parent][i];
            if(!visited[sibling]){
                visited[sibling] = true;
                q.push(sibling);
            }
        }
    }
}

void clear_visited(){
    for(int i = 0 ; i < 1001 ; i++){
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        arr[parent].push_back(child);
        arr[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(arr[i].begin() , arr[i].end());
    }

    DFS(v);
    clear_visited();
    cout << '\n';
    BFS(v);

    return 0;
}