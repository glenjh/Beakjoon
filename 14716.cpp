#include <iostream>

using namespace std;

int m,n;

int arr[251][251];
bool visited[251][251];

int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 8 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= m || move_y >= n){ continue; }
        if( !visited[move_x][move_y] && arr[move_x][move_y] == 1){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    int cnt = 0;
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if( !visited[i][j] && arr[i][j] == 1){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}