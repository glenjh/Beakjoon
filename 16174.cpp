#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[4][4];
int dir_x[2] = {1, 0};
int dir_y[2] = {0, 1}; 

bool visited[4][4];
bool flag = false;

void BFS(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()){
        int curr_x = q.front().first, curr_y = q.front().second;
        q.pop();

        if(arr[curr_x][curr_y] == -1){
            flag = true;
            return;
        }

        for(int i = 0 ; i < 2 ; i++){
            int x_move = curr_x + (dir_x[i] * arr[curr_x][curr_y]);
            int y_move = curr_y + (dir_y[i] * arr[curr_x][curr_y]);

            if(x_move < 0 || y_move < 0 || x_move >= n || y_move >= n){ continue; }
            if(!visited[x_move][y_move]){
                q.push({x_move, y_move});
                visited[x_move][y_move] = true;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }
    BFS(0, 0);
    if(flag){ cout << "HaruHaru"; }
    else{ cout << "Hing"; }

    return 0;
}