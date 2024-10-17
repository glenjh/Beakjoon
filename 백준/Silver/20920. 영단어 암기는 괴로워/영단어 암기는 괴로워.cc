#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

unordered_map<string, int> words;

bool comp(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        if(a.first.length() != b.first.length()){
            return a.first.length() > b.first.length();
        }
        else{
            return a.first < b.first;
        }
    }
}   

int main() {
    FastIO();

    int n, m;
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;

        if(input.length() >= m){
            words[input] += 1;
        }
    }

    vector<pair<string, int>> v(words.begin(), words.end());

    sort(v.begin(), v.end(), comp);

    for(auto it : v){
        cout << it.first << '\n';
    }

    return 0;
}