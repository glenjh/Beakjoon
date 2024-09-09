#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[202][202];

int main() {
    FastIO();

    ll n, k;
    cin >> n >> k;

    for(ll i = 0 ; i < 202 ; i++){
        dp[1][i] = i;
    }

    for(ll i = 2 ; i <= n ; i++){
        for(ll j = 1 ; j <= k ; j++){
            dp[i][j] = dp[i - 1][j]+ dp[i][j - 1];
            dp[i][j] %= 1000000000;
        }
    }

    cout << dp[n][k] % 1000000000 << '\n';

    return 0;
}