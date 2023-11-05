#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, cnt;
int** maze = new int*[n];


int dir_x[4] = {0, -1, 0, 1};
int dir_y[4] = {1, 0, -1, 0};
int moving_dist[101][101] = {0, };
bool visited[101][101] = {false, };

void BFS(int x , int y){
    queue<pair<int,int>> q;

    q.push(pair<int,int>(x, y));
    visited[x][y] = true;
    moving_dist[x][y] += 1;

    while(!q.empty()){
        int x_pos = q.front().first, y_pos = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int x_move = x_pos + dir_x[i];
            int y_move = y_pos + dir_y[i];
            if(x_move < 0 || y_move < 0 || x_move >= n || y_move >= m){ continue; }

            if(maze[x_move][y_move] == 1 && !visited[x_move][y_move]){
                moving_dist[x_move][y_move] = moving_dist[x_pos][y_pos] + 1;
                visited[x_move][y_move] = true;
                q.push(pair<int,int>(x_move, y_move));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        maze[i] = new int[m];
    }
    

    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < m ; j++){
            maze[i][j] = s[j] - '0';
        }
    }
    BFS(0, 0);
    cout << moving_dist[n-1][m-1];
    return 0;
}