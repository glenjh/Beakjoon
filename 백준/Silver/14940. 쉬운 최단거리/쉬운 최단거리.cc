#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, startX, startY;
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};
int arr[MAX][MAX];
int rel[MAX][MAX];
queue<pair<int, int>> q;

bool visited[MAX][MAX];

int BFS(int x, int y){
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int nx = currX + dirX[i];
            int ny = currY + dirY[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            if(arr[nx][ny] == 0){ continue; }
            if(!visited[nx][ny]){
                q.push({nx, ny});
                rel[nx][ny] = rel[currX][currY] + 1;
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
            rel[i][j] = -1;

            if(arr[i][j] == 2){
                rel[i][j] = 0;
                startX = i, startY = j;
            }
        }
    }

    BFS(startX, startY);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(rel[i][j] == -1){
                if(arr[i][j] == 0){
                    rel[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << rel[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}