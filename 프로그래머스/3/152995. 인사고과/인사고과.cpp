#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    for(int i = 0 ; i < scores.size() ; i++){
        v.push_back({scores[i][0], scores[i][1]});
    }
    sort(v.begin(), v.end(), comp);
    
    int wanhoScoreA = scores[0][0], wanhoScoreB = scores[0][1];
    int M = -1;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i].second > M){
            M = v[i].second;
        }
        else if(v[i].second < M){
            if(v[i].first == wanhoScoreA && v[i].second == wanhoScoreB){
                answer = -1;
                break;
            }
            else{
                continue;
            }
        }
        
        if(v[i].first + v[i].second > wanhoScoreA + wanhoScoreB){
            answer += 1;
        }
    }
    
    return answer;
}