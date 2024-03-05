#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    
    for(auto it : participant){
        m[it]++;
    }
    
    for(auto it : completion){
        m[it]--;
    }
    
    for(auto it : m){
        if(it.second > 0){
            answer = it.first;
        }
    }
    
    return answer;
}