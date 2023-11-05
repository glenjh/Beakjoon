#include <iostream>
#include <vector>

using namespace std;

int arr[51][51];
int dir_x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dir_y[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool visited[51][51];

int w, h;

void DFS(int x, int y){
    visited[x][y] = true;

    for(int i = 0 ; i < 8 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];
        if(move_x < 0 || move_x >= h || move_y < 0 || move_y >= w){ continue; }

        if(!visited[move_x][move_y] && arr[move_x][move_y]){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    int cnt = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cnt = 0;
        cin >> w >> h;

        if(w == 0 && h == 0){ break; }

        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                visited[i][j] = false;
                cin >> arr[i][j];
            }
        }
        
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if( !visited[i][j] && arr[i][j] == 1){ 
                    DFS(i, j); 
                    cnt += 1;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}