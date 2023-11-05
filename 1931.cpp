#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<long long,long long>> v;

    int n, cnt = 1;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin() , v.end() , comp);

    int first_meeting_end = v[0].second;
    
    for(int i = 1 ; i < v.size() ; i++){
        if(v[i].first >= first_meeting_end){
            cnt++;
            first_meeting_end = v[i].second;
        }
    }
    cout << cnt;
    return 0;
} 