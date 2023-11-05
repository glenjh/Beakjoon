#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, most_high = 0;

int arr[101][101];
int my_arr[101][101];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[101][101];

void reset(){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= n){ continue; }
        if( !visited[move_x][move_y] && my_arr[move_x][move_y] == 1){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
            if(arr[i][j] > most_high){ most_high = arr[i][j]; }
        }
    }

    for(int levels = 0 ; levels <= most_high ; levels++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(levels >= arr[i][j]){
                    my_arr[i][j] = 0;
                }else{ my_arr[i][j] = 1; }
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && my_arr[i][j] == 1){
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        v.push_back(cnt);
        reset();
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-1];
    return 0;
}