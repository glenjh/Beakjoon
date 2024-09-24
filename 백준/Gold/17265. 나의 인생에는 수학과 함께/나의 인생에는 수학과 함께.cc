#include <iostream>
#include <vector>
#include <string>
#include <climits>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
ll m = INT_MAX, M = INT_MIN;
int dirX[2] = {0, 1};
int dirY[2] = {1 ,0};

char arr[5][5];
bool visited[5][5];

void DFS(int x, int y, int curr, char sign){
    if(visited[x][y]){ return; }
    visited[x][y] = true;

    
    if (arr[x][y] == '+' || arr[x][y] == '-' || arr[x][y] == '*'){
        sign = arr[x][y];
    }
    else{
        if(sign == '+'){
            curr += (arr[x][y] - '0');
        }
        else if(sign == '-'){
            curr -= (arr[x][y] - '0');
        }
        else if(sign == '*'){
            curr *= (arr[x][y] - '0');
        }
    }

    if(x == n - 1 && y == n - 1){
        if(m > curr){
            m = curr;
        }
        if(M < curr){
            M = curr;
        }
        return;
    }

    for(int i = 0 ; i < 2 ; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx >= n || ny >= n){ continue; }
        if(!visited[nx][ny]){
            DFS(nx, ny, curr, sign);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    DFS(0, 0, arr[0][0] - '0', ' ');
    cout << M << ' ' << m << '\n';

    return 0;
}