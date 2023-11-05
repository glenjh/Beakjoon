#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool com(pair<string,int> a, pair<string,int> b){
    if(a.second == b.second){
        return a.first < b.first; 
    }else{
        return a.second > b.second;
    }
}

int main(){
    int n;
    string name;
    cin >> n;
    unordered_map<string,int> m;
    
    for(int i=0 ; i<n ; i++){
        cin >> name;
        if(m.find(name) == m.end()) { m.insert(pair<string,int>(name, 1)); }
        else{m[name]++;}
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin() , v.end(), com);

    cout << v[0].first;
    return 0;
}