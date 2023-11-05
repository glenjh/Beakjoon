#include <iostream>
#include <vector>

using namespace std;

int k, v, e;
vector<int> my_vec[20001];

bool visited[20001];
bool flag;
int color[20001] = {0, };

void clear(){
    for(int i = 0 ; i < 20001 ; i++){
        visited[i] = false;
        color[i] = 0;
        my_vec[i].clear();
    }
}

void DFS(int x){
    visited[x] = true;
    
    for(int i = 0 ; i < my_vec[x].size() ; i++){
        int child = my_vec[x][i];
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
    
    cin >> k;
    for(int testcase = 0 ; testcase < k ; testcase++){
        flag = true;
        cin >> v >> e;

        for(int i = 0 ; i < e ; i++){
            int parent, child;
            cin >> parent >> child;
            my_vec[parent].push_back(child);
            my_vec[child].push_back(parent);
        }

        for(int i = 1 ; i <= v ; i++){
            if(flag){ DFS(i); }
            else{ break; }
        }
        if(flag){ cout << "YES" << '\n'; }
        else { cout << "NO" << '\n'; }
        clear();
    }
    return 0;
}