#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
vector<string> answer;
bool visited[10001];
bool able = false;

void DFS(string s, vector<vector<string>> v){
    answer.push_back(s);
    if(cnt == v.size()){ able = true; }
    
    for(int i = 0 ; i < v.size() ; i++){
        if(!visited[i] && v[i][0] == s){
            visited[i] = true;
            cnt += 1;
            DFS(v[i][1], v);
            
            if(!able){
                answer.pop_back();
                cnt -= 1;
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets);
    return answer;
}