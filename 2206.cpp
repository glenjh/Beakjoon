#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m,answer;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[1001][1001];

bool visited[1001][1001][2];
bool chanceVisited[1001][1001];
bool flag = false;

void BFS(int x, int y, int chance, int cnt){
    queue< pair<pair<int, int>, pair<int, int>> > q;
    q.push( {{x, y}, {chance, cnt}} );
    visited[x][y][chance] = true;

    while(!q.empty()){
        int curr_x = q.front().first.first;
        int curr_y = q.front().first.second;
        int curr_chance = q.front().second.first;
        int curr_cnt = q.front().second.second;
        q.pop();

        if(curr_x == n-1 && curr_y == m-1){
            answer = curr_cnt;
            flag = true;
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = curr_x + dir_x[i];
            int ny = curr_y + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            if(visited[nx][ny][curr_chance]){ continue; }
            
            if(arr[nx][ny] == '0'){
                visited[nx][ny][curr_chance] = true;
                q.push({{nx, ny}, {curr_chance, curr_cnt+1}});
            }
            else if(arr[nx][ny] == '1'){
                if(curr_chance == 1){ continue; }
                else{
                    visited[nx][ny][curr_chance+1] = true;
                    q.push({{nx, ny}, {curr_chance+1, curr_cnt+1}});
                }
            }
        }
    }
}

void FaseIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FaseIO();

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    BFS(0, 0, 0, 1);

    if(flag){
        cout << answer << '\n';
    }else{
        cout << -1 << '\n';
    }

    return 0;
}