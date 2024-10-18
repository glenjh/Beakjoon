#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt;

char arr[5] = {'A', 'E', 'I', 'O', 'U'};
string temp = "";

void DFS(int len, string target){
    if(temp == target){
        answer = cnt;
        return;
    }
    
    if(len == 5){
        return;
    }
    
    for(int i = 0 ; i < 5 ; i++){
        temp += arr[i];
        cnt += 1;
        
        DFS(len + 1, target);
        
        temp.pop_back();
    }
}

int solution(string word) {
    DFS(0, word);
    
    return answer;
}