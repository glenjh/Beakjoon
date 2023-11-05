#include <iostream>
#include <queue>

using namespace std;

int l, curr_x, curr_y, target_x, target_y;

int dir_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dir_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool visited[301][301];
int cnt[301][301] = {0, };

queue<pair<int,int>> q;

void reset(){
    for(int i = 0 ; i < 301 ; i++){
        for(int j = 0 ; j < 301 ; j++){
            visited[i][j] = false;
            cnt[i][j] = 0;
        }
    }
    while (!q.empty()){
        q.pop();
    }
}

void BFS(int x, int y){
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()){
        int first_x = q.front().first;
        int first_y = q.front().second;
        q.pop();

        if(first_x == target_x && first_y == target_y){
            cout << cnt[first_x][first_y] << '\n';
            return;
        }

        for(int i = 0 ; i < 8 ; i++){
            int next_x = first_x + dir_x[i];
            int next_y = first_y + dir_y[i];
            if(next_x < 0 || next_y < 0 || next_x >= l || next_y >= l){ continue; }
            if(!visited[next_x][next_y]){
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
                cnt[next_x][next_y] = cnt[first_x][first_y] + 1;
            }

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int testcase = 0 ; testcase < t ; testcase++){
        cin >> l;
        cin >> curr_x >> curr_y;
        cin >> target_x >> target_y;
        BFS(curr_x , curr_y);
        reset();
    }
    return 0;
}