#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(pair<string, int> a, pair<string, int> b){
    return a < b;
}

int main() {
    FastIO();

    unordered_map<string, int> m;
    vector<pair<string, int>> v;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int idx;
        string input, temp = "";
        cin >> input;

        for(int j = 0 ; j < input.length() ; j++){
            char c = input[j];
            if(c == '.'){
                idx = j;
                break;
            }
        }

        for(int j = idx + 1 ; j < input.length() ; j++){
            temp += input[j];
        }

        if(m.find(temp) == m.end()){
            m.insert({temp, 1});
        }else{
            m[temp] += 1;
        }
    }

    for(auto it : m){
        v.push_back(it);
    }
    
    sort(v.begin(), v.end(), comp);

    for(auto it : v){
        cout << it.first << ' ' << it.second << '\n';
    }

    return 0;
}