#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0 ; i < numbers.size() ; i++){
        answer.push_back(-1);
    }
    
    stack<int> s;
    for(int i = numbers.size() - 1 ; i >= 0 ; i--){
        if(s.empty()){
            s.push(numbers[i]);
        }
        else{
            while(true){
                if(s.empty()){
                    s.push(numbers[i]);
                    break; 
                }
                if(numbers[i] < s.top()){
                    answer[i] = s.top();
                    s.push(numbers[i]);
                    break; 
                }else{
                    s.pop();
                }
            }
        }
    }
    
    
    return answer;
}