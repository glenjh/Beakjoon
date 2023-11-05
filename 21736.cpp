#include <iostream>
#include <string>

using namespace std;

int n, m, curr_x_pos, curr_y_pos, cnt = 0;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[601][601];

bool visited[601][601];

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    if(arr[x][y] == 'P'){
        cnt++;
    }

    for(int i = 0 ; i < 4; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m){ continue; }
        if(!visited[move_x][move_y] && arr[move_x][move_y] != 'X'){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m; 

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j];
            if(input[j] == 'I'){
                curr_x_pos = i;
                curr_y_pos = j;
            }
        }
    }

    DFS(curr_x_pos, curr_y_pos);

    if(cnt == 0){
        cout << "TT" << '\n';
    }else{
        cout << cnt << '\n';
    }
    
    return 0;
}