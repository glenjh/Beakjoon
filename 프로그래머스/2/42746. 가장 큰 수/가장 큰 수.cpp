#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto it : numbers){
        v.push_back(to_string(it));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(auto it : v){
        answer += it;
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    return answer;
}