#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[201];

bool visited[201];

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    
    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            DFS(nx);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0 ; i < computers.size() ; i++){
        for(int j = 0 ; j < computers[i].size() ; j++){
            if(i != j && computers[i][j] == 1){
                v[i + 1].push_back(j + 1);
            }
        }
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            DFS(i);
            answer += 1;
        }
    }
    
    return answer;
}