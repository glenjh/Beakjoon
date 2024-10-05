#include <iostream>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int r, c, ans = -1;
int arr[5][5];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

bool visited[5][5];

void BFS(int x, int y, int cnt){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, cnt});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int currCnt = q.front().second;
        q.pop();

        if(arr[cx][cy] == 1){
            ans = currCnt;
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5){ continue; }
            if(!visited[nx][ny] && arr[nx][ny] != -1){
                visited[nx][ny] = true;
                q.push({{nx, ny}, currCnt + 1});
            }
        }
    }   
}

int main() {
    FastIO();

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;

    BFS(r, c, 0);
    cout << ans << '\n';

    return 0;
}