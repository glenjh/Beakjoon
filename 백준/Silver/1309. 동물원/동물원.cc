#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[100001][3]; // xx, ox, xo

int main() {
    FastIO();

    int n;
    cin >> n;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 1 ; i <= n ; i++){
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

        dp[i][0] %= 9901;
        dp[i][1] %= 9901;
        dp[i][2] %= 9901;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901 << '\n';

    return 0;
}