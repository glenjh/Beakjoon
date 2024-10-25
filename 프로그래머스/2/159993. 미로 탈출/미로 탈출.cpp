#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

char arr[101][101];

bool visited[101][101][2];

int startX, startY, leverX, leverY, endX, endY;
int W, H;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int cnt[101][101][2];

void BFS(int x, int y, bool levered){
    queue< pair<pair<int, int>, bool> > q;
    q.push({{x, y}, levered});
    visited[x][y][levered] = true;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cLevered = q.front().second;
        q.pop();
        
        if(cx == endX && cy == endY && cLevered){
            return;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= H || ny >= W){ continue; }
            if(!visited[nx][ny][cLevered] && arr[nx][ny] != 'X'){
                bool nextLever = cLevered;
                if(arr[nx][ny] == 'L' && !nextLever){
                    nextLever = true;
                }
                cnt[nx][ny][nextLever] = cnt[cx][cy][cLevered] + 1;
                visited[nx][ny][nextLever] = true;
                q.push({{nx, ny}, nextLever});
            }
        }
    }
}

int solution(vector<string> maps) {
    W = maps[0].size();
    H = maps.size();
    int answer = 0;
    
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].length() ; j++){
            if(maps[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            else if(maps[i][j] == 'L'){
                leverX = i;
                leverY = j;
            }
            else if(maps[i][j] == 'E'){
                endX = i;
                endY = j;
            }
            arr[i][j] = maps[i][j];
        }
    }
    
    BFS(startX, startY, false);
    
    if(cnt[endX][endY][true] == 0){
        answer = -1;
    }
    else{
        answer = cnt[endX][endY][true];
    }
    
    return answer;
}