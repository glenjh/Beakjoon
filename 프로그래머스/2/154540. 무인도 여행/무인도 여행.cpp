#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char arr[101][101];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int cnt = 0;
vector<int> answer;

bool visited[101][101];

void DFS(int x, int y, int w, int h){
    if(visited[x][y]){ return; }
    visited[x][y] = true;
    cnt += arr[x][y] - '0';
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w){ continue; }
        if(!visited[nx][ny] && arr[nx][ny] != 'X'){
            DFS(nx, ny, w, h);
        }
    }
}

vector<int> solution(vector<string> maps) {
    
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            arr[i][j] = maps[i][j];
        }
    }
    
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(!visited[i][j] && arr[i][j] != 'X'){
                DFS(i, j, maps[0].size(), maps.size());
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}