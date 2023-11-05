#include <iostream>
#include <string>

using namespace std;

int r, c;
int total_sheep = 0, total_wolf = 0, sheep = 0, wolf = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[251][251];
char arr[251][251];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    if(arr[x][y] == 'v'){ wolf += 1; }
    else if(arr[x][y] == 'k'){ sheep += 1; }

    for(int i = 0 ; i < 4 ; i++){
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];
        if(next_x < 0 || next_y < 0 || next_x >= r || next_y >= c){ continue; }
        if(!visited[next_x][next_y] && arr[next_x][next_y] != '#'){
            DFS(next_x, next_y);
        }
    }
}

int main(){
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
                if(wolf >= sheep){
                    total_wolf += wolf;
                }else if(wolf < sheep){
                    total_sheep += sheep;
                }
                sheep = 0;
                wolf = 0;
            }
        }
    }
    cout << total_sheep << " " << total_wolf << '\n';

    return 0;
}