#include <iostream>
#include <vector>

using namespace std;

long long n, m, answer;
int arr[501][501];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int dp[501][501];

int DFS(int x, int y){
    if(x == n-1 && y == m-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 0;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        if(arr[x][y] <= arr[nx][ny]) { continue; }
        dp[x][y] = dp[x][y] + DFS(nx, ny);
    }
    return dp[x][y];
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    for(int i = 0 ; i < 501 ; i++){
        for(int j = 0 ; j < 501 ; j++){
            dp[i][j] = -1;
        }
    }

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    answer = DFS(0, 0);
    cout << answer << '\n';

    return 0;
}