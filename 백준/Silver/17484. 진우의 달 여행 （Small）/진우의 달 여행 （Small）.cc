#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, answer = INT_MAX;
int arr[7][7];
pair<int, int> dir[3] = { {1, -1}, {1, 0}, {1, 1} };

void DFS(int x, int y, int cnt, int prev){
    if(x == n - 1 && (0 <= y && y < m)){
        answer = min(answer, cnt);
        return;
    }

    for(int i = 0 ; i < 3 ; i++){
        if (i != prev){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            DFS(nx, ny, cnt + arr[nx][ny], i);
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < m ; i++){
        DFS(0, i, arr[0][i], -1);
    }

    cout << answer << '\n';

    return 0;
}