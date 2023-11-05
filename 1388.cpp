#include <iostream>
#include <string>

using namespace std;

int n, m, cnt = 0;

bool visited[51][51];
char arr[51][51];

int dir[2] = {-1, 1};

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    if(arr[x][y] == '-'){
        for(int i = 0 ; i < 2 ; i++){
            int move_y = y + dir[i];
            if(move_y < 0 || move_y >= m){ continue; }
            if(!visited[x][move_y] && arr[x][move_y] == '-'){
                DFS(x, move_y);
            }
        }
    }
    else if(arr[x][y] == '|'){
        for(int i = 0 ; i < 2 ; i++){
            int move_x = x + dir[i];
            if(move_x < 0 || move_x >= n){ continue; }
            if(!visited[move_x][y] && arr[move_x][y] == '|'){
                DFS(move_x, y);
            }
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

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j]){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}