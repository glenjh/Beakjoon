#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int arr[501][501];
int mark[501][501];
map<int, int> m;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int idx = 1;

bool visited[501][501];

int BFS(int x, int y, int cnt, int w, int h){
    queue< pair<pair<int, int>, int> > q;
    q.push({{x, y}, cnt});
    visited[x][y] = true;
    int oil = 0;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cCnt = q.front().second;
        q.pop();
        
        mark[cx][cy] = idx;
        oil++;
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w){ continue; }
            if(!visited[nx][ny] && arr[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push({{nx, ny}, cCnt + 1});
            }
        }
    }
    
    return oil;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    for(int i = 0 ; i < land.size() ; i++){
        for(int j = 0 ; j < land[i].size() ; j++){
            arr[i][j] = land[i][j];
        }
    }
    
    for(int i = 0 ; i < land.size() ; i++){
        for(int j = 0 ; j < land[i].size() ; j++){
            if(land[i][j] == 1 && !visited[i][j]){
                m[idx] = BFS(i, j, 0, land[0].size(), land.size());
                idx++;
            }
        }
    }
    
    for(int pipe = 0 ; pipe < land[0].size() ; pipe++){
        int currPipe = -1, temp = 0; 
        set<int> s;
        for(int i = 0 ; i < land.size() ; i++){
            if(mark[i][pipe] != 0 && 
               mark[i][pipe] != currPipe && 
               s.find(mark[i][pipe]) == s.end()){
                s.insert(mark[i][pipe]);
                currPipe = mark[i][pipe];
                temp += m[currPipe];
            }
        }
        answer = max(answer, temp);
    }

    return answer;
}