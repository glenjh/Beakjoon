#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
int arr[501][501];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

bool visited[501][501];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void reset(){
    for(int i = 0 ; i < 501 ; i++){
        for(int j = 0 ; j < 501 ; j++){
            visited[i][j] = false;
        }
    }
}

void one(int x, int y){
    if(x+1 >= n || x+2 >= n || y+1 >= m){ return; }

    int sum = arr[x][y];
    sum += arr[x+1][y] + arr[x+1][y+1] + arr[x+2][y];
    answer = max(sum, answer);
} // ㅏ

void two(int x, int y){
    if (x+1 >= n || x+2 >= n || y-1 < 0){
        return;
    }

    int sum = arr[x][y];
    sum += arr[x+1][y] + arr[x+2][y] + arr[x+1][y-1];
    answer = max(sum, answer);
} // ㅓ

void three(int x, int y){
    if (x+1 >= n || y+1 >= m || y+2 >= m){
        return;
    }

    int sum = arr[x][y];
    sum += arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1];
    answer = max(sum, answer);
} // ㅜ

void four(int x, int y){
    if (x-1 < 0 || y+2 >= m || y+1 >= m){
        return;
    }

    int sum = arr[x][y];
    sum += arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1];
    answer = max(sum, answer);
} // ㅗ

void DFS(int x, int y, int cnt, int sum){
    visited[x][y] = true;

    if(cnt == 3){
        answer = max(answer, sum);
        return;
    }

    for(int i = 0 ; i < 4; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        if(!visited[nx][ny]){
            visited[nx][ny] = true;
            int nextSum = sum + arr[nx][ny];
            DFS(nx, ny, cnt+1, nextSum);
            visited[nx][ny] = false;
        }
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
            reset();
            DFS(i, j, 0, arr[i][j]);
            one(i, j);
            two(i, j);
            three(i, j);
            four(i, j);
        }
    }

    cout << answer << '\n';

    return 0;
}