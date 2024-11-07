#include <iostream>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

queue<pair<int, int>> fire;

int r, c, ans;
int startX, startY;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

int fireMap[1001][1001];

bool visited[1001][1001];
bool flag = false;

char arr[1001][1001];

void BFS(int x, int y, int cnt){
    queue< pair<pair<int, int>, int> > q;
    q.push({{x, y}, cnt});
    visited[x][y] = true;

    while(!fire.empty()){
        int cfx = fire.front().first;
        int cfy = fire.front().second;
        fire.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nfx = cfx + dirX[i];
            int nfy = cfy + dirY[i];
            if(nfx < 0 || nfy < 0 || nfx >= r || nfy >= c){ continue; }
            if(arr[nfx][nfy] != '#' && fireMap[nfx][nfy] > fireMap[cfx][cfy] + 1){
                fireMap[nfx][nfy] = fireMap[cfx][cfy] + 1;
                fire.push({nfx, nfy});
            }
        }
    }

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cCnt = q.front().second;
        q.pop();

        if(cx == r - 1 || cy == c - 1 || cx == 0 || cy == 0){
            flag = true;
            ans = cCnt;
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c){ continue; }
            if(arr[nx][ny] != '#' && !visited[nx][ny]){
                if(fireMap[nx][ny] > cCnt + 1){
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, cCnt + 1});
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> r >> c;

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            fireMap[i][j] = 9999999;
        }
    }

    for(int i = 0 ; i < r ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
            if(input[j] == 'F'){
                fire.push({i, j});
                fireMap[i][j] = 0;
            }
            else if(input[j] == 'J'){
                startX = i;
                startY = j;
            }
        }
    }

    BFS(startX, startY, 0);

    if(!flag){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        cout << ans + 1 << '\n';
    }

    return 0;
}