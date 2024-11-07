#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[501];

int main() {
    FastIO();

    vector<pair<int, int>> v;
    int n; 
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        dp[i] = 1;
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(v[i].second > v[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int M = -1;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] > M){
            M = dp[i];
        }
    }

    cout << n - M << '\n';

    return 0;
}