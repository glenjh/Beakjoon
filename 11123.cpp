#include <iostream>
#include <string>

using namespace std;

bool visited[101][101];

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int t, h, w, cnt;

char arr[101][101] ;

void clear(){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= h || move_y >= w){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] == '#'){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int testcase = 0 ; testcase < t ; testcase++){
        cin >> h >> w;
        cnt = 0;

        for(int i = 0 ; i < h ; i++){
            string input;
            cin >> input;
            for(int j = 0 ; j < input.length() ; j++){
                arr[i][j] = input[j];
            }
        }

        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(!visited[i][j] && arr[i][j] == '#'){
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        clear();
    }
    return 0;
}