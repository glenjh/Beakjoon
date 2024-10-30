#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, pair<int, int>> > v;

int p[101];

int My_Find(int a){
    if(p[a] == a){ return a; }
    else{
        return p[a] = My_Find(p[a]);
    }
}

void My_Uni(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);
    
    if(pa != pb){
        p[pa] = pb;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0 ; i <= n ; i++){
        p[i] = i;
    }
    
    for(int i = 0 ; i < costs.size() ; i++){
        v.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0 ; i < v.size() ; i++){
        int pa = My_Find(v[i].second.first);
        int pb = My_Find(v[i].second.second);
            
        if(pa != pb){
            answer += v[i].first;
            My_Uni(v[i].second.first, v[i].second.second);
        }
    }
    
    return answer;
}