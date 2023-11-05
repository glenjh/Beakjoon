#include <iostream>
#include <queue>

using namespace std;

int m, n, h;
int arr[101][101][101];
int cnt[101][101][101];
int dir_x[6] = {0, 0, 1, -1, 0, 0};
int dir_y[6] = {0, 0, 0, 0, 1, -1};
int dir_z[6] = {1, -1, 0, 0, 0, 0};
queue<pair<int, pair<int, int>>> q;

bool flag = true;

void check(){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if(arr[i][j][k] == 0){
                    flag = false;
                    break;
                }
            }
        }
    }
}


void find(){
    int M = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if(cnt[i][j][k] >= M){
                    M = cnt[i][j][k];
                }
            }
        }
    }
    cout << M << '\n';
}

void BFS(){
    while (!q.empty()){
        int curr_z = q.front().first;
        int curr_x = q.front().second.first;
        int curr_y = q.front().second.second;
        q.pop();

        for(int i = 0 ; i < 6 ; i++){
            int move_z = curr_z + dir_z[i];
            int move_x = curr_x + dir_x[i];
            int move_y = curr_y + dir_y[i];

            if(move_z < 0 || move_x < 0 || move_y < 0 || move_z >= h || move_x >= n || move_y >= m){ continue; }
            if(cnt[move_z][move_x][move_y] > 0){ continue; }

            if(arr[move_z][move_x][move_y] == 0){
                q.push({move_z, {move_x, move_y}});
                arr[move_z][move_x][move_y] = 1;
                cnt[move_z][move_x][move_y] = cnt[curr_z][curr_x][curr_y] + 1;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({i, {j, k}});
                }
            }
        }
    }

    BFS();
    check();

    if(flag == false){
        cout << -1 << '\n';
        return 0;
    }else{
        find();
    }

    return 0;
}