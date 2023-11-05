#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int color[2001] = {0,};
vector<int> v[2001];
queue<int> q;

bool visited[2001];
bool flag = true;

void BFS(int x){
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i];
            if(!visited[next]){
                color[next] = (color[curr] + 1) % 2;
                visited[next] = true;
                q.push(next);
            }else{
                if(color[curr] == color[next]){ flag = false; }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        if(flag){ BFS(i); }
        else{ break; }
    }

    if(flag){ cout << 1; }
    else{ cout << 0; }

    return 0;
}