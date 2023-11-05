#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, answer;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), comp);

    answer = v[0].first + v[0].second;

    for(int i = 1 ; i < n ; i++){
        if (answer > v[i].first){
            answer += v[i].second;
        }else{
            answer = v[i].first;
            answer += v[i].second;
        }
        
    }

    cout << answer << '\n';

    return 0;
}