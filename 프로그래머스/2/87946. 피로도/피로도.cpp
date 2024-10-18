#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> nums, v;
vector<vector<int>> d;
int fullK, temp, answer;

bool visited[9];

void DFS(int cnt, vector<int> nums, int k){
    if(cnt == nums.size()){
        fullK = k;
        temp = 0;
        
        for(int i = 0 ; i < v.size() ; i++){
            if(fullK >= d[v[i]][0]){
                fullK -= d[v[i]][1];
                temp += 1;
            }
        }
        answer = max(answer, temp);
        return;
    }
    
    for(int i = 0 ; i < nums.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            
            DFS(cnt + 1, nums, k);
            
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    d = dungeons;
    for(int i = 0 ; i < dungeons.size() ; i++){
        nums.push_back(i);
    }
    
    DFS(0, nums, k);
    
    return answer;
}