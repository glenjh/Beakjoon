#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define MAX 101

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

queue<pair<int, int>> water;
queue<pair<int, int>> q;
int r, c;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[MAX][MAX];

void WaterMove(){
    int len = water.size();
    for(int i = 0 ; i < len ; i++){
        int cx = water.front().first;
        int cy = water.front().second;
        water.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dir_x[i];
            int ny = cy + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c){ continue; }
            if(arr[nx][ny] != '.'){ continue; }
            arr[nx][ny] = '*';
            water.push({nx, ny});
        }
    }
}

long long int Smove(long long int cnt){
    while(!q.empty()){
        cnt++;
        WaterMove();
        int cx = q.front().first;
        int cy = q.front().second;

        int len = q.size();
        for(int i = 0 ; i < len ; i++){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = cx + dir_x[i];
                int ny = cy + dir_y[i];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c){ continue; }
                if(arr[nx][ny] == 'D'){
                    return cnt;
                }
                if(arr[nx][ny] != '.'){ continue; }
                arr[nx][ny] = 'S';
                q.push({nx, ny});
            }
        } 
    }

    return -1;
}


int main() {
    FastIO();

    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*'){
                water.push({i, j});
            }else if(arr[i][j] == 'S'){
                q.push({i, j});
            }
        }
    }

    long long int ans = Smove(0);
    if(ans == -1){
        cout << "KAKTUS" << '\n';
    }else{
        cout << ans << '\n';
    }

    return 0;
}