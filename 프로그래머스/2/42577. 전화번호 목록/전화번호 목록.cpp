#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> m;
    
    for(auto it : phone_book){
        m[it] = 1;
    }
    
    for(int i = 0 ; i < phone_book.size() ; i++){
        string temp = "";
        for(int j = 0 ; j < phone_book[i].size() ; j++){
            temp += phone_book[i][j];
            
            if(m[temp] && temp != phone_book[i]){
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}