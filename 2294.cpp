#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, k, rel;
    int coins[101];
    int dp[10001];

    cin >> n >> k;

    for(int i = 0 ; i <= k ; i++){
        dp[i] = 100001;
    }
    dp[0] = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j <= k ; j++){
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if(dp[k] == 100001){
        cout << -1 << '\n';
    }else{
        cout << dp[k] << '\n';
    }

    return 0;
}