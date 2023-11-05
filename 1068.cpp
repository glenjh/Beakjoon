# include <iostream>
# include <vector>
using namespace std;
vector<int> nodes[50];
int leaf;
int del_leaf;
int delete_num;
bool del_visited[50] = {false,};
bool visited[50] = {false,};

void del_dfs(int a){
    if(del_visited[a] == true){ return; }
    del_visited[a] = true;
    if(nodes[a].size() == 0){
        del_leaf++;
        return;
    }
    for(int i=0 ; i<nodes[a].size() ; i++){
        del_dfs(nodes[a][i]);
    }
}

void dfs(int a){
    if(visited[a] == true){ return; }
    visited[a] = true;
    if(nodes[a].size() == 0){
        leaf++;
        return;
    }
    else if(nodes[a].size() == 1 ){
        if(nodes[a][0] == delete_num){
            leaf++;
        }
    }
    for(int i=0 ; i<nodes[a].size() ; i++){
            dfs(nodes[a][i]);
    } 
}

int main(){
    int n, num, root;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> num;
        if(num == -1){
            root = i;
        }else{
            nodes[num].push_back(i);
        }
    }
    cin >> delete_num;
    
    if(root == delete_num){
        cout << 0;
    }else{
        dfs(root);
        del_dfs(delete_num);
        cout << leaf-del_leaf;
    }
    return 0;
}