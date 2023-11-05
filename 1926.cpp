#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt = 0, picture_size = 0;

int arr[501][501];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[501][501];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    picture_size += 1;

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            int move_x = x + dir_x[i];
            int move_y = y + dir_y[i];

            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m){ continue; }
            if( !visited[move_x][move_y] && arr[move_x][move_y] == 1){
                DFS(move_x, move_y);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sizes;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if( !visited[i][j] && arr[i][j] == 1){
                DFS(i, j);
                cnt++;
                sizes.push_back(picture_size);
                picture_size = 0;
            }
        }
    }

    sort(sizes.begin(), sizes.end());

    cout << cnt << '\n';
    if(cnt == 0){ cout << 0; }
    else{ cout << sizes[sizes.size() -1 ]; }
    return 0;
}