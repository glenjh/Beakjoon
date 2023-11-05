#include <iostream>
#include <string>

using namespace std;

int n, normal_cnt, abnormal_cnt;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

string arr[101][101];
string blind_arr[101][101];

bool visited[101][101];
bool visited2[101][101];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= n){ continue; }
        if( !visited[move_x][move_y] && (arr[x][y] == arr[move_x][move_y]) ){
            DFS(move_x, move_y);
        }
    }
}

void color_blind_DFS(int x, int y){
    if(visited2[x][y]){ return; }
    visited2[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= n){ continue; }
        if( !visited2[move_x][move_y] && (blind_arr[x][y] == blind_arr[move_x][move_y]) ){
            color_blind_DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
            if(input[j] == 'G'){ blind_arr[i][j] = 'R'; }
            else{ blind_arr[i][j] = input[j]; }    
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j]){
                DFS(i, j);
                normal_cnt++;
            }
            if(!visited2[i][j]){
                color_blind_DFS(i, j);
                abnormal_cnt++;
            }
        }
    }
    cout << normal_cnt << " " << abnormal_cnt;
    return 0;
}