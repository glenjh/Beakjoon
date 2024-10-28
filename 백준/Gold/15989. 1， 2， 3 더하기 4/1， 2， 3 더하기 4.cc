#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[10001][10001];

int main() {
    FastIO();

    dp[1][1] = 1;
    dp[2][1] = 1, dp[2][2] = 1;
    dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;

    for (int i = 4; i <= 10001; i++){
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }

    return 0;
}