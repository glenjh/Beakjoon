#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[101][101];
int dp[101][101];
int dirX[2] = {0, 1};
int dirY[2] = {1, 0};

int DFS(int x, int y, int m, int n){
    if(x == n && y == m){ return 1; }
    if(dp[y][x] != 0){ return dp[y][x]; }
    
    for(int i = 0 ; i < 2 ; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx > n || ny > m || arr[ny][nx] == 1){ continue; }
        dp[y][x] += DFS(nx, ny, m, n) % 1000000007;
    }
    return dp[y][x] % 1000000007;
}

// 가로 m, 세로 n
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0 ; i < puddles.size() ; i++){
        arr[puddles[i][0]][puddles[i][1]] = 1;
    }
    
    answer = DFS(1, 1, m, n);
    
    return answer;
}