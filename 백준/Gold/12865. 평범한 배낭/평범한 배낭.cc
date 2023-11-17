#include <iostream>
#include <vector>
#define CNT_MAX 101
#define WEI_MAX 100001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[CNT_MAX][WEI_MAX];

int main() {
    FastIO();

    int n, k;
    vector<pair<int, int>> v;
    v.push_back({0, 0});

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            if(j >= v[i].first){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }   
    }

    cout << dp[n][k] << '\n';

    return 0;
}