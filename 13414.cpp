#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
bool com(const pair<string,int> &a , const pair<string,int> &b){
    return a.second < b.second;
}

int main(){
    int k, l;
    string school_id;
    map<string,int> list;
    cin >> k >> l;
    for(int i=0 ; i<l ; i++){
        cin >> school_id;
        list[school_id] = i;
    }
    vector<pair<string,int>> v;
    for(auto &it : list){
        v.push_back(it);
    }
    sort(v.begin(), v.end() , com);
    for(int i=0 ; i<min(k,(int)v.size()) ; i++){
        cout << v[i].first << '\n';
    }
    return 0;
}