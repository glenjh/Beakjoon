#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt;
vector<int> v;

void DFS(int x, int idx, int dep, int tar, int len){
    if(dep == len){
        if(x == tar){
            cnt += 1;
        }
        return;
    }
    DFS(x + v[dep], idx, dep + 1, tar, len);
    DFS(x - v[dep], idx, dep + 1, tar, len);
}

int solution(vector<int> numbers, int target) {
    int answer = 0, len = numbers.size();
    
    for(auto it : numbers){
        v.push_back(it);
    }
    
    DFS(0, 0, 0, target, numbers.size());
    answer = cnt;
    
    return answer;
}