#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool com(pair<int,int> a , pair<int,int> b){
    if(a.first != b.first) { return a < b; }
    else if(a.first == b.first) { 
        return a.second < b.second;
    }
}

int main(){
    int testcase;
    cin >> testcase;
    pair<int,int> point;
    vector<pair<int, int>> v;
    for(int i=0 ; i<testcase ; i++){
        cin >> point.first >> point.second;
        v.push_back(point);

    }
    sort(v.begin(), v.end(), com);
    for(int j=0 ; j<v.size() ; j++){
        cout << v[j].first << " " << v[j].second << '\n';
    }
    return 0;
}