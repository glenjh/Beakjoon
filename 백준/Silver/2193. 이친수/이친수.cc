#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    long long dp[91];
    dp[0] = 1, dp[1] = 1;

    int n;
    cin >> n;

    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n-1] << '\n';

    return 0;
}