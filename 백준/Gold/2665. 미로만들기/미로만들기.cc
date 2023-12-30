#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#define MAX 51

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
char arr[MAX][MAX];
int visited[MAX][MAX];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void BFS(int x, int y){
    visited[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dir_x[i];
            int ny = cy + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }

            if(arr[nx][ny] == '1'){
                if(visited[nx][ny] > visited[cx][cy]){
                    visited[nx][ny] = visited[cx][cy];
                    q.push({nx, ny});
                }
            }else if(arr[nx][ny] == '0'){
                if(visited[nx][ny] > visited[cx][cy] + 1){
                    visited[nx][ny] = visited[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            visited[i][j] = INT_MAX;
        }
    }

    BFS(0, 0);
    if(visited[n - 1][n - 1] == INT_MAX){
        cout << 0 << '\n';
    }else{
        cout << visited[n - 1][n - 1] << '\n';
    }

    return 0;
}