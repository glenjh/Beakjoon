#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[1000001];
int color[1000001] ={0, };

bool flag = true;
bool visited[1000001];

void DFS(int x){
    visited[x] = true;
    
    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(!visited[child]){
            color[child] = (color[x] + 1) % 2;
            DFS(child);
        }else if(visited[child]){
            if(color[child] == color[x]){
                flag = false;
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
        if(flag){ DFS(i); }
        else{  
            break;
        }
    }

    if(flag){ cout << "POSSIBLE" << '\n'; }
    else{ cout << "IMPOSSIBLE" << '\n'; }

    return 0;
}