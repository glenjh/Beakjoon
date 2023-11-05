#include <iostream>
#include <string>

using namespace std;

bool visited[101][101];
char arr[101][101];

int r, c, cnt = 0, limit = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    limit++;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];
        if(move_x < 0 || move_y < 0 || move_x >= r || move_y >= c){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] == '#'){
            if(limit <= 2){
                DFS(move_x, move_y);
            }else{
                limit = 0;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for(int i = 0 ; i < r ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(arr[i][j] == '#' && !visited[i][j]){
                DFS(i, j);
                cnt++;
                limit = 0;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}