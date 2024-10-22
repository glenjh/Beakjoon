#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

bool visited[101];

vector<int> v[101];
int cnt;

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    cnt += 1;
    
    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            DFS(nx);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX, idx;
    
    
    for(int i = 0 ; i < wires.size() ; i++){
        vector<int> temp;
        idx = i;
        for(int j = 0 ; j < wires.size() ; j++){
            if(j != idx){
                v[wires[j][0]].push_back(wires[j][1]);
                v[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        for(int j = 1 ; j <= n ; j++){
            if(!visited[j]){
                DFS(j);
                temp.push_back(cnt);
                if(temp.size() == 2){
                    answer = min(answer, abs(temp[0] - temp[1]));
                    temp.clear();
                }
                cnt = 0;
            }
        }
        cout << '\n';
        
        for(int j = 1 ; j <= n ; j++){
            v[j].clear();
            visited[j] = false;
        }
    }
    
    return answer;
}