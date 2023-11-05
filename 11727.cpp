#include <iostream>

using namespace std;

long long dp[1001] = {0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 1, dp[1] = 3, dp[2] = 5;
    int n;
    cin >> n;

    for(int i = 3 ; i < n ; i++){
        dp[i] = (dp[i - 1] + (dp[i - 2]) * 2) % 10007;
    }

    cout << dp[n-1]  << '\n';

    return 0;
}