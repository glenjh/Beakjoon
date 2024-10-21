#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    while(k > 0){
        for(int i = 1 ; i < number.length() ; i++){
            if(number[i - 1] - '0' < number[i] - '0'){
                number.erase(number.begin() + (i - 1));
                k--;
                break;
            }
            
            if(i == number.length() - 1){
                number.pop_back();
                k--;
            }
        }
    }
    
    answer = number;
    
    return answer;
}