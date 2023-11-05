#include <iostream>

using namespace std;

int dp[1000001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int n;
    cin >> n;

    for(int i = 3 ; i <= n ; i++){
        dp[i] = dp[i - 1] % 15746 + dp[i - 2] % 15746;
    }

    cout << dp[n] % 15746 << '\n';

    return 0;
}