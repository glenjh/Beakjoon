#include <iostream>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dir_y[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int n, m;
int arr[101][71];
int cnt;

bool visited[101][71];

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    bool isTop = true;

    while (!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++){
            int nx = currX + dir_x[i];
            int ny = currY + dir_y[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            if(arr[nx][ny] == 0){ continue; }
            if(arr[nx][ny] > arr[currX][currY]){
                isTop = false;
            }
            if (!visited[nx][ny] && arr[nx][ny] == arr[currX][currY]){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    if(isTop){
        cnt++;
    }
}

int main(){
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && arr[i][j] != 0){
                BFS(i, j);
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}