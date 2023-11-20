#include <iostream>
#define MAX 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX];

int main() {
    FastIO();

    int n, k;
    int coins[MAX];
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }

    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j <= k ; j++){
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}