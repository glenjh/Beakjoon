#include <iostream>
#define N 21
#define M 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int testCase;
    cin >> testCase;
    for(int t = 0 ; t < testCase ; t++){
        int n, k;
        int coins[N];
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> coins[i];
        }

        cin >> k;
        int dp[M];
        for(int i = 0 ; i <= k ; i++){
            dp[i] = 0;
        }

        dp[0] = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = coins[i] ; j <= k ; j++){
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }

        cout << dp[k] << '\n';
    }

    return 0;
}