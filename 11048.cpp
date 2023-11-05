#include <iostream>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[1001][1001];
int cnt[1001][1001] = {0, };
int dir_x[3] = {1, 0, 1};
int dir_y[3] = {0, 1, 1};
int n, m, answer;

bool visited[1001][1001] = {false, };

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0 ; i < 3 ; i++){
            int nX = currX + dir_x[i];
            int nY = currY + dir_y[i];

            if(nX >= n || nY >= m){ continue; }

            if(!visited[nX][nY]){
                q.push({nX, nY});
                cnt[nX][nY] = cnt[currX][currY] + arr[nX][nY];
                visited[nX][nY] = true;
            }
            else{
                if(cnt[nX][nY] < cnt[currX][currY] + arr[nX][nY]){
                    cnt[nX][nY] = cnt[currX][currY] + arr[nX][nY];
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    cnt[0][0] = arr[0][0];

    BFS(0, 0);
    
    cout << cnt[n-1][m-1] << '\n';

    return 0;
}