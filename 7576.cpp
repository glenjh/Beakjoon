#include <iostream>
#include <queue>

using namespace std;

int m ,n;
int arr[1001][1001];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int cnt[1001][1001];
queue<pair<int, int>> q;

bool visited[1001][1001];
bool flag = true;

void find(){
    int M = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(cnt[i][j] >= M){
                M = cnt[i][j];
            }
        }
    }
    cout << M;
}

void BFS(int x, int y){
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()){
        int curr_x = q.front().first, curr_y = q.front().second;

        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int next_x = curr_x + dir_x[i];
            int next_y = curr_y + dir_y[i];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m){ continue; }
            if(arr[next_x][next_y] == 0 && !visited[next_x][next_y]){
                q.push({next_x, next_y});
                arr[next_x][next_y] = 1;
                cnt[next_x][next_y] = cnt[curr_x][curr_y] + 1;
                visited[next_x][next_y] = true;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({i, j});
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                BFS(i, j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0){
                flag = false;
                break;
            }
        }
    }
    if(!flag){
        cout << -1;
        return 0;
    }else{
        find();
    }

    return 0;
}