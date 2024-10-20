#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[51];

bool OneDiff(string a, string b){
    int cnt = 0;
    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] != b[i]){
            cnt += 1;
        }
    }
    
    if(cnt == 1){
        return true;
    }
    else{
        return false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0, cnt = 0;
    
    queue<pair<string, int>> q;
    q.push({begin, cnt});
    
    while(!q.empty()){
        string cWord = q.front().first;
        int cCnt = q.front().second;
        q.pop();
        
        if(cWord == target){
            answer = cCnt;
            return answer;
        }
        
        for(int i = 0 ; i < words.size() ; i++){
            if(!visited[i] && OneDiff(cWord, words[i])){
                visited[i] = true;
                q.push({words[i], cCnt + 1});
            }
        }
    }
     
    return answer;
}