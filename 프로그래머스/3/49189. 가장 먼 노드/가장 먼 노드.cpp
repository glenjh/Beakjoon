#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[20001];
int arr[20001];
int M = 0;

bool visited[20001];

void DFS(int x, int dep, int target){
    if(visited[x]){ return; }
    visited[x] = true;
    arr[x] = dep;
    
    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            DFS(nx, dep + 1, target);
        }
    }
}

void BFS(int x, int dep){
    queue<pair<int, int>> q;
    q.push({x, dep});
    visited[x] = true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cDep = q.front().second;
        q.pop();
        
        arr[cx] = cDep;
        M = max(M, cDep);
        
        for(int i = 0 ; i < v[cx].size() ; i++){
            int nx = v[cx][i];
            if(!visited[nx]){
                visited[nx] = true;
                q.push({nx, cDep + 1});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0 ; i < edge.size() ; i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    BFS(1, 0);
    
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == M){
            answer += 1;
        }
    }
    
    return answer;
}