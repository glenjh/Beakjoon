#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i = 0 ; i < enemy.size() ; i++){
        q.push(enemy[i]);
        if(q.size() > k){
            cnt += q.top();
            q.pop();
        }
        
        if(cnt > n){
            return i;
        }
    }
    
    return enemy.size();
}