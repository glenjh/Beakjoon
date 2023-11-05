#include <iostream>
#include <queue>

using namespace std;

int k, w, h, answer = -1;
int arr[201][201];
int dirX[4] = {0 ,1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int horseDirX[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int horseDirY[8] = {1, -1, 2, -2, 1, -1, 2, -2};

bool visited[201][201][31];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int x, int y, int cnt, int horse){
    queue< pair<pair<int, int>, pair<int, int>> > q;
    q.push({{x, y}, {cnt, horse}});
    visited[x][y][horse] = true;

    while(!q.empty()){
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int currCnt = q.front().second.first;
        int currHorse = q.front().second.second;
        q.pop();

        if(currX == h-1 && currY == w-1){
            answer = currCnt;
            return;
        }

        if(currHorse > 0){
            for(int i = 0 ; i < 8 ; i++){
                int nx = currX + horseDirX[i];
                int ny = currY + horseDirY[i];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w){ continue; }
                if(!visited[nx][ny][currHorse-1] && arr[nx][ny] == 0){
                    q.push({{nx, ny}, {currCnt+1, currHorse-1}});
                    visited[nx][ny][currHorse-1] = true;
                }
            }
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = currX + dirX[i];
            int ny = currY + dirY[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w){ continue; }
            if(!visited[nx][ny][currHorse] && arr[nx][ny] == 0){
                q.push({{nx, ny}, {currCnt+1, currHorse}});
                visited[nx][ny][currHorse] = true;
            }
        }
    }
}

int main(){
    FastIO();

    cin >> k >> w >> h;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cin >> arr[i][j];
        }
    }

    BFS(0, 0, 0, k);

    cout << answer << '\n';

    return 0;
}