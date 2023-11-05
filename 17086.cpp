#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n, m, len = 0;
int arr[51][51];
int dir_x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dir_y[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int cnt[51][51] = {0, };

set<int> s;

bool visited[51][51];

void reset(){
    for(int i = 0 ; i < 51 ; i++){
        for(int j = 0 ; j < 51 ; j++){
            visited[i][j] = false;
            cnt[i][j] = 0;
        }
    }
}

void BFS(int x, int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()){
        int curr_x = q.front().first, curr_y = q.front().second;
        q.pop();

        if(arr[curr_x][curr_y] == 1){
            s.insert(cnt[curr_x][curr_y]);
            if(len < cnt[curr_x][curr_y]){
                len = cnt[curr_x][curr_y];
            }
            return;
        }
        
        for(int i = 0 ; i < 8 ; i++){
            int x_move = curr_x + dir_x[i];
            int y_move = curr_y + dir_y[i];
            if(x_move < 0 || y_move < 0 || x_move >= n || y_move >= m){ continue; }
            if(!visited[x_move][y_move]){
                q.push({x_move, y_move});
                cnt[x_move][y_move] = cnt[curr_x][curr_y] + 1;
                visited[x_move][y_move] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && arr[i][j] == 0){
                BFS(i, j);
                reset();
            }
        }
    }
    cout << len;
    return 0;
}