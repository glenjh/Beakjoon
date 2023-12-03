#include <iostream>
#include <string>
#include <set>

using namespace std;

int r, c, rel = 0;
int cnt[21][21] = {0, };
bool visited[26];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

char arr[21][21];

void DFS(int x, int y, int cnt){
    set<int> s;
    s.insert(arr[x][y]);

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c || s.find(arr[nx][ny]) != s.end() || visited[arr[nx][ny] - 'A']){
            continue;
        }

        visited[arr[nx][ny] - 'A'] = true;
        DFS(nx, ny, cnt + 1);
        visited[arr[nx][ny] - 'A'] = false;
    }

    rel = max(rel, cnt);
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