#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
int arr[301][301];
int melt[301][301];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

bool visited[301][301];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void reset(){
    for(int i = 0 ; i < 301 ; i++){
        for(int j = 0 ; j < 301 ; j++){
            visited[i][j] = false;
        }
    }
}

void GetMeltAmount(int x, int y){
    int amount = 0;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
        if(arr[nx][ny] == 0){
            amount += 1;
        }
    }
    melt[x][y] = amount;
}

void Melt(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            arr[i][j] -= melt[i][j];
            if(arr[i][j] < 0){
                arr[i][j] = 0;
            }
        }
    }
}

void Calc(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] > 0){
                GetMeltAmount(i, j);
            }
        }
    }

    Melt();
}

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    // visited[x][y] = cnt;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
       
        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            if(!visited[nx][ny] && arr[nx][ny] > 0){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
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

    while(true){
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j] && arr[i][j] > 0){
                    BFS(i, j);
                    cnt += 1;
                }
            }
        }

        if(cnt == 0){
            cout << 0 << '\n';
            return 0;
        }
        
        if(cnt > 1){ break; }
        else{
            ans += 1;
            Calc();
            reset();
        }
    }

    cout << ans << '\n';

    return 0;
}