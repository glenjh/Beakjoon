#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<pair<int, int>> v;
    int n, ans = 0, M = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int l, h;
        cin >> l >> h;
        if(h > M){
            M = h;
        }
        v.push_back({l, h});
    }

    sort(v.begin(), v.end());

    int l = 0, r = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i].second == M){
            r = i;
            if(l == 0){
                l = i;
            }
        }
    }

    int lStart = v[0].first;
    int lHeight = v[0].second;
    for(int i = 1 ; i < l ; i++){
        if(v[i].second > lHeight){
            ans += (v[i].first - lStart) * lHeight;
            lStart = v[i].first;
            lHeight = v[i].second;
        }
    }
    ans += (v[l].first - lStart) * lHeight;

    ans += (v[r].first - v[l].first + 1) * M;

    int rStart = v[v.size() - 1].first;
    int rHeight = v[v.size() - 1].second;
    for(int i = v.size() - 2 ; i > r ; i--){
        if(v[i].second > rHeight){
            ans += ((rStart + 1) - (v[i].first + 1)) * rHeight;
            rStart = v[i].first;
            rHeight = v[i].second;
        }
    }

    ans += ((rStart + 1) - (v[r].first + 1)) * rHeight;

    cout << ans << '\n';

    return 0;
}