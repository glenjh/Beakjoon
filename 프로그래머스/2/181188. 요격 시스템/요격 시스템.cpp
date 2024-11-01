#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        a.first < b.first;
    }
}

vector<pair<int, int>> v;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    for(int i = 0 ; i < targets.size() ; i++){
        v.push_back({targets[i][0], targets[i][1]});  // 시작점, 끝점
    }
    
    sort(v.begin(), v.end(), comp);
    
    int startPoint = v[0].first;
    int endPoint = v[0].second;
    
    for(int i = 1 ; i < v.size() ; i++){
        if(endPoint <= v[i].first){
            answer += 1;
            startPoint = v[i].first; 
            endPoint = v[i].second;
        }
    }
    
    return answer;
}