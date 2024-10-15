#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map <string, int> m;

bool comp(pair<pair<int ,string>, int> a, pair<pair<int ,string>, int> b){
    string aGenre = a.first.second;
    string bGenre = b.first.second;
    
    int aCnt = a.second;
    int bCnt = b.second;
    int aID = a.first.first;
    int bID = b.first.first;
    
    if(aGenre != bGenre){
        return m[aGenre] > m[bGenre];
    }
    else{
        if(aCnt != bCnt){
            return aCnt > bCnt;
        }
        else{
            return aID < bID;
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<pair<pair<int ,string>, int>> songs;
    unordered_map <string, int> cnts;
    vector<int> answer;
    
    for(int i = 0 ; i < genres.size() ; i++){
        songs.push_back({{i, genres[i]}, plays[i]}); 
        m[genres[i]] += plays[i];
    }
    
    sort(songs.begin(), songs.end(), comp);
    
    for(auto it : songs){
        if(cnts[it.first.second] < 2){
            answer.push_back(it.first.first);
            cnts[it.first.second] += 1;
        }
    }
    
    return answer;
}