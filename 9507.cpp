#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long dp[70] = {0, };

int main(){
    FastIO();

    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
    int n;
    cin >> n;

    for (int i = 4; i <= 70; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        cout << dp[input] << '\n';
    }

    return 0;
}