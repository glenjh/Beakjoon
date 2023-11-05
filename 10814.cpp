#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool com(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    pair<int, string> p;
    vector<pair<int, string>> v;
    for(int i=0 ; i<n ; i++){
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    
    stable_sort(v.begin(), v.end(), com);
    for(int i=0 ; i<n ; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}