#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

map<string, int> words;

bool comp(string a, string b){
    if(words[a] != words[b]){
        return words[a] > words[b];
    }
    else{
        if(a.length() != b.length()){
            return a.length() > b.length();
        }
        else{
            return a < b;
        }
    }
}   

int main() {
    FastIO();

    set<string> s;
    vector<string> v;
    int n, m;
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;

        if(input.length() >= m){
            words[input] += 1;
            s.insert(input);
        }
    }

    for(auto it : s){
        v.push_back(it);
    }

    sort(v.begin(), v.end(), comp);

    for(auto it : v){
        cout << it << '\n';
    }

    return 0;
}