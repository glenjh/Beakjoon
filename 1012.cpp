#include <iostream>

using namespace std;

int arr[51][51];
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};
bool visited[51][51];

int m,n;

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x > m || move_y > n){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] == 1){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, k, cnt;
    cin >> T;

    for(int i = 0 ; i < T ; i++){
        cnt = 0;
        for(int a = 0 ; a < 51 ; a++){ // 방문기록, 밭 상태 초기화
            for(int b = 0 ; b < 51 ; b++){
                arr[a][b] = 0;
                visited[a][b] = false;
            }
        }

        cin >> m >> n >> k;
        for(int j = 0 ; j < k ; j++){
            int pos_x, pos_y;
            cin >> pos_x >> pos_y;
            arr[pos_x][pos_y] = 1;
        }

        for(int a = 0 ; a < 51 ; a++){
            for(int b = 0 ; b < 51 ; b++){
                if(!visited[a][b] && arr[a][b] == 1){
                    cnt++;
                    DFS(a, b);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}