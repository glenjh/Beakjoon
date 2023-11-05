#include <iostream>
#include <queue>
#include <string>

using namespace std;

int r, c, sheep_cnt = 0, wolf_cnt = 0, final_sheep_cnt = 0 , final_wolf_cnt = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[251][251];

bool visited[251][251] = {false, };

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    if(arr[x][y] == 'o'){ sheep_cnt += 1; }
    if(arr[x][y] == 'v'){ wolf_cnt += 1; }

    for(int i = 0 ; i < 4 ; i++){
        int move_x = dir_x[i] + x, move_y = dir_y[i] + y;
        if(move_x < 0 || move_y < 0 || move_x >= r || move_y >= c){ continue; }

        if(!visited[move_x][move_y] && arr[move_x][move_y] != '#'){
            DFS(move_x, move_y);
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
            if(!visited[i][j] && arr[i][j] != '#'){
                DFS(i, j);
                if(wolf_cnt >= sheep_cnt){
                    final_wolf_cnt += wolf_cnt;
                }else{
                    final_sheep_cnt += sheep_cnt;
                }
                sheep_cnt = 0, wolf_cnt = 0;
            }
        }
    }

    cout << final_sheep_cnt << ' ' << final_wolf_cnt;

    return 0;
}