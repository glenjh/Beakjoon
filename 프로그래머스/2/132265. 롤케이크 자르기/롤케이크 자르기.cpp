#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> a, b;
    
    for(int i = 0 ; i < topping.size() ; i++){
        a[topping[i]] += 1;
    }
    
    for(int i = 0 ; i < topping.size() ; i++){
        a[topping[i]] -= 1;
        b[topping[i]] += 1;
        
        if(a[topping[i]] == 0){
            a.erase(topping[i]);
        }
        
        if(a.size() == b.size()){
            answer += 1;
        }
    }
    
    return answer;
}