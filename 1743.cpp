#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , m, k, cnt = 0;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

char arr[101][101] = {'.',};

bool visited[101][101] = {false, };

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    cnt++;

    for(int i = 0 ; i < 4 ; i++){
        int x_move = x + dir_x[i];
        int y_move = y + dir_y[i];

        if( x_move < 0 || y_move < 0 || x_move > n || y_move > m ){ continue; }
        if(!visited[x_move][y_move] && arr[x_move][y_move] == '#'){
            DFS(x_move, y_move);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    cin >> n >> m >> k;

    for(int i = 0 ; i < k ; i++){
        int x_pos, y_pos;
        cin >> x_pos >> y_pos;
        arr[x_pos-1][y_pos-1] = '#';
    }

    for(int i = 0 ; i <  n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( !visited[i][j] && arr[i][j] == '#'){
                DFS(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    if(v.empty()){ cout << 0; }
    else{
        sort(v.begin() , v.end());
        cout << v[v.size() - 1];
    }
    
    return 0;
}