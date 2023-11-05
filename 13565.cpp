#include <iostream>
#include <string>

using namespace std;

int n, m;
char arr[1001][1001];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[1001][1001];
bool flag = false;

void DFS(int x, int y){
    if(visited[x][y]){return;}
    visited[x][y] = true;
    if(x == n-1){ flag = true; }

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];
        if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m){ continue; }
        if(!visited[move_x][move_y] && arr[x][y] == arr[move_x][move_y]){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    for(int i = 0 ; i < m ; i++){
        if(!visited[0][i] && arr[0][i] == '0'){
            DFS(0, i);
        }
    }
    if(flag){ cout << "YES"; }
    else{ cout << "NO"; }

    return 0;
}