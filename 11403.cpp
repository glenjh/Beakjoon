#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> v[100];

bool visited[100];

void clear(){
    for(int i = 0 ; i < 100 ; i++){
        visited[i] = false;
    }
}

void DFS(int x){
    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(!visited[child]){
            visited[child] = true;
            DFS(child);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int input;
            cin >> input;
            if(input == 1){
                v[i].push_back(j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        clear();
        DFS(i);
        for(int j = 0 ; j < n ; j++){
            if(visited[j]){ cout << 1 << " ";}
            else{ cout << 0 << " "; }
        }
        cout << '\n';
    }

    return 0;
}