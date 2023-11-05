#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

static bool comp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    else{
        return a.second > b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        m[input] += 1;
    }

    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    cout << v[0].first << " " << v[0].second << '\n';
    return 0;
}