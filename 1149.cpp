#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pair<int, int>> dir = {{1, 1}, {1, -1}, {1, 2}, {1, -2}};
int v[1001][3];
int min_v[1001][3];
int n, answer = 987654321;

void DFS(int x, int y, int cnt){
    if(cnt > answer){ return; }
    if(x == n-1){
        answer = min(answer, cnt);
        return;
    }
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if(nx < 0 || ny < 0 || nx >= n || ny >= 3){ continue; }
        if(min_v[nx][ny] <= cnt + v[nx][ny]){ continue; }
        else{
            min_v[nx][ny] = cnt + v[nx][ny];
        }
    
        DFS(nx, ny, min_v[nx][ny]);
    }
}

int main(){
    FastIO();

    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> v[i][j];
            min_v[i][j] = answer;
        }
    }

    for(int i = 0 ; i < 3 ; i++){
        min_v[0][i] = v[0][i];
    }

    for(int i = 0 ; i < 3 ; i++){
        DFS(0, i, v[0][i]);
    }

    cout << answer << '\n';

    return 0;
}