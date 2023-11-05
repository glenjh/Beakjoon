#include <iostream>
#include <vector>

using namespace std;

int answer, n ,m, t;
int arr[1001][1001];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[1001][1001];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        if(!visited[nx][ny] && arr[nx][ny] != 0){
            DFS(nx, ny);
        }
    }
}

void FaseIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FaseIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m*3 ; j++){
            int input;
            cin >> input;
            arr[i][j/3] += input;
        }
    }

    cin >> t;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] / 3 >= t){
                arr[i][j] = 255;
            }else{
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && arr[i][j] != 0){
                DFS(i, j);
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}