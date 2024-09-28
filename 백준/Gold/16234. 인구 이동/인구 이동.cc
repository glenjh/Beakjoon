#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, l, r, ans, peopleCnt, unionCnt;
int arr[51][51];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;

bool visited[51][51];
bool flag;

void Print()
{
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Reset(){
    flag = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            visited[i][j] = false;
        }
    }
}

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    peopleCnt = 0;
    unionCnt = 0;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        v.push_back({cx, cy});
        peopleCnt += arr[cx][cy];   
        unionCnt += 1;

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
            int sub = abs(arr[cx][cy] - arr[nx][ny]);
            if (!visited[nx][ny] && (l <= sub && sub <= r)){
                flag = true;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j]){
                    BFS(i, j);
                    if(flag){
                        int avgPeopleCnt = peopleCnt / unionCnt;
                        for(auto it : v){
                            arr[it.first][it.second] = avgPeopleCnt;
                        }
                        // Print();
                    }
                    v.clear();
                }
            }
        }
        if(flag){
            ans += 1;
        }else{ break; }
        Reset();
    }

    cout << ans << '\n';

    return 0;
}