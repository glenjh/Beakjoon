#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r, c, k, t_cnt = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[6][6];

bool visited[6][6];

void DFS(int x, int y, int cnt){

    if(x == 0 && y == c-1){
        if(cnt == k){
            t_cnt += 1;
            return;
        }
    }

    for(int i = 0 ; i < 4 ; i++){
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];

        if(next_x < 0 || next_y < 0 || next_x >= r || next_y >= c){ continue; }
        if(arr[next_x][next_y] == 'T'){ continue; }
        if(visited[next_x][next_y]){ continue; }

        visited[next_x][next_y] = true;
        DFS(next_x, next_y, cnt+1);
        visited[next_x][next_y] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;
    for(int i = 0 ; i < r ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }

    visited[r-1][0] = true;
    DFS(r-1, 0, 1);
    cout << t_cnt << '\n';

    return 0;
}