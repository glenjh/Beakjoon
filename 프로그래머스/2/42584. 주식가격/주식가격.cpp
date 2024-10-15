#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len);
    stack<int> s;
    
    for(int i = 0 ; i < len ; i++){
        if(s.empty()){
            s.push(i);
        }
        else{
            while(!s.empty() && prices[i] < prices[s.top()]){
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    
    while(!s.empty()){
        answer[s.top()] = len - 1 - s.top();
        s.pop();
    }
    
    return answer;
}