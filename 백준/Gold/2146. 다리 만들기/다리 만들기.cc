#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int islandNum = 1;
int n;
int arr[101][101];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

bool visited[101][101];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    arr[x][y] = islandNum;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
        if(!visited[nx][ny] && arr[nx][ny] == 1){
            DFS(nx, ny);
        }
    }
}

int ans = 1000;
void BFS(int x, int y, int cnt, int num){

    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, cnt});
    visited[x][y] = false;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cCnt = q.front().second;
        q.pop();

        if(arr[cx][cy] != num && arr[cx][cy] != 0){
            ans = min(ans, cCnt);
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
            if(!visited[nx][ny]){
                if(arr[nx][ny] == 0 || arr[nx][ny] != num){
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, cCnt + 1});
                }
            }
        }
    }
}

void Reset(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            visited[i][j] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && arr[i][j] == 1){
                DFS(i, j);
                islandNum += 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] != 0 && !visited[i][j]){
                BFS(i, j, 0, arr[i][j]);
                Reset();
            }
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}