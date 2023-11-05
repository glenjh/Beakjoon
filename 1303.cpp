#include <iostream>
#include <string>

using namespace std;

int n, m, w_cnt = 0, b_cnt = 0, total_w = 0, total_b = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[101][101];

bool visited[101][101];

void clear(){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j ++){
            visited[i][j] = false;
        }
    }
}

void DFS_w(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    w_cnt++;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i]; 
        int move_y = y + dir_y[i];
        
        if(move_x < 0 || move_y < 0 || move_x >= m || move_y >= n){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] == 'W'){
            
            DFS_w(move_x, move_y);
        }
    }
}

void DFS_b(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    b_cnt++;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i]; 
        int move_y = y + dir_y[i];
        
        if(move_x < 0 || move_y < 0 || move_x >= m || move_y >= n){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] == 'B'){
            DFS_b(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && arr[i][j] == 'W'){
                DFS_w(i, j);
                total_w += w_cnt * w_cnt;
                w_cnt = 0;
            }
        }
    }

    clear();

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && arr[i][j] == 'B'){
                DFS_b(i, j);
                total_b += b_cnt * b_cnt;
                b_cnt = 0;
            }
        }
    }

    cout << total_w << " " << total_b;

    return 0;
}