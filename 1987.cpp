#include <iostream>
#include <string>

using namespace std;

int r, c, rel = 0;
int cnt[21][21] = {0, };
bool visited[26];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[21][21];

void DFS(int x, int y, int cnt){
    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];
        if(move_x < 0 || move_y < 0 || move_x >= r || move_y >= c){ continue; }
        if(visited[arr[move_x][move_y] - 'A']){
            if(cnt >= rel){
                rel = cnt;
            } 
            continue; 
        }
        visited[arr[move_x][move_y] - 'A'] = true;
        DFS(move_x, move_y, cnt+1);
        visited[arr[move_x][move_y] - 'A'] = false;

    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
        }
    }
    visited[arr[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << rel << '\n';
    return 0;
}