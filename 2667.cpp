#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[26][26] = {0, };
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0}; 

int cnt, n, h_size;

bool visited[26][26] = {false, };


void DFS(int x, int y){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    h_size++;

    for(int i = 0 ; i < 4 ; i++){
        int move_x = x + dir_x[i];
        int move_y = y + dir_y[i];

        if(move_x < 0 || move_y < 0 || move_x >= n || move_y > n){ continue; }
        if( !visited[move_x][move_y] && arr[move_x][move_y] == 1 ){
            DFS(move_x, move_y);
        }
    }
}

int main(){
    vector<int> s;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < n ; j++){
            arr[i][j] = input[j] - '0';
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && arr[i][j] == 1){ 
                DFS(i, j); 
                cnt++;
                s.push_back(h_size);
                h_size = 0;
            }
        }
    }
    sort(s.begin() , s.end());
    cout << cnt << '\n';
    for(auto it : s){ cout << it << '\n'; }

    return 0;
}