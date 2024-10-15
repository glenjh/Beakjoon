#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> v;
    queue<pair<int, int>> q; // 우선순위, 위치
    
    for(int i = 0 ; i < priorities.size() ; i++){
        q.push({priorities[i], i});
        v.push_back(priorities[i]);
    }
    
    
    sort(v.begin(), v.end(), comp);
    
    int ans = 0;
    for(int i = 0 ; i < v.size() ; i++){
        int curr = v[i];
        
        while(true){
            int now = q.front().first;
            int pos = q.front().second;
            q.pop();
            
            if(now == curr){
                ans += 1;
                if(pos == location){
                    answer = ans;
                }
                break;
            }
            q.push({now, pos});
        }
    }
    
    return answer;
}