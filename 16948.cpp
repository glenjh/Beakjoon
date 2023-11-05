#include <iostream>
#include <queue>

using namespace std;

int n, r1, c1, r2, c2;
int cnt[201][201] = {0, };
int dir_x[6] = {-2, -2, 0, 0, 2, 2};
int dir_y[6] = {-1, 1, -2, 2, -1, 1};

bool visited[201][201];

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int curr_x = q.front().first, curr_y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 6 ; i++){
            int next_x = curr_x + dir_x[i];
            int next_y = curr_y + dir_y[i];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= n){ continue; }
            if(!visited[next_x][next_y]){
                cnt[next_x][next_y] = cnt[curr_x][curr_y] + 1;
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    BFS(r1, c1);

    if(cnt[r2][c2] == 0){ cout << -1; }
    else{ cout << cnt[r2][c2]; }

    return 0;
}