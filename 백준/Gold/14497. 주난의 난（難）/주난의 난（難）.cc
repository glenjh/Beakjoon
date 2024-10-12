#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int curr;
int n, m, startX, startY, endX, endY, ans;
int dist[301][301];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

char arr[301][301];

bool visited[301][301];
bool flag;

void Reset(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            visited[i][j] = false;
        }
    }
}

void BFS(int x, int y){
    Reset();
    curr += 1;
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m ){ continue; }
            if(!visited[nx][ny]){

                if (arr[nx][ny] == '#'){
                    flag = true;
                }
                visited[nx][ny] = true;
                if (arr[nx][ny] == '1'){
                    dist[nx][ny] = curr;
                    arr[nx][ny] = '0';
                }
                else if(arr[nx][ny] == '0'){
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m;
    cin >> startX >> startY >> endX >> endY;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dist[i][j] = INF;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j + 1] = input[j];
        }
    }

    dist[startX][startY] = 0;
    while(true){
        BFS(startX, startY);

        if(flag){
            cout << curr << '\n';
            break;
        }
    }

    return 0;
}