#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, int> m;

bool comp(int a, int b){
    if(m[a] != m[b]){
        return m[a] > m[b];
    }
    else{
        return a > b;
    }
    
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i = 0 ; i < tangerine.size() ; i++){
        m[tangerine[i]] += 1;
    }
    
    sort(tangerine.begin(), tangerine.end(), comp);
    
    int size = 0;
    for(int i = 0 ; i < tangerine.size() ; i++){
        if(k <= 0){ break; }
        
        if(tangerine[i] != size){
            size = tangerine[i];
            answer += 1;
        }
        k--;
    }
    
    return answer;
}