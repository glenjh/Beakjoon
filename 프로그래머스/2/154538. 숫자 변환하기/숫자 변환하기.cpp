#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int addN, answer;
bool visited[1000001];

void BFS(int x, int cnt, int target){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cCnt = q.front().second;
        q.pop();
        
        if(cx == target){
            answer = cCnt;
            return;
        }
        
        if(cx + addN <= target && !visited[cx + addN]){
            visited[cx + addN] = true;
            q.push({cx + addN, cCnt + 1});
        }
        
        if(cx * 2 <= target && !visited[cx * 2]){
            visited[cx * 2] = true;
            q.push({cx * 2, cCnt + 1});
        }
        
        if(cx * 3 <= target && !visited[cx * 3]){
            visited[cx * 3] = true;
            q.push({cx * 3, cCnt + 1});
        }
    }
}

int solution(int x, int y, int n) {
    addN = n;
    
    if(x == y){
        answer = 0;
    }
    else{
        BFS(x, 0, y);
    
        if(answer == 0){
            answer = -1;
        }
    }
    
    return answer;
}