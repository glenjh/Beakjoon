// 1 -> 1                          1개
// 2 -> 2                          1개
// 3 -> 3, 1 2, 2 1                3개


// 4 -> 1 3, 1 2 1, 3 1            3개
// 5 -> 2 3, 3 2, 1 3 1, 2 1 2     4개
// 6 ->
// 7 ->                            9개

//             1   2   3
//         1   1   0   0
//         2   0   1   0
//         3   1   1   1
//         4   2   0   1
//         5   1   2   1
//         6   3   3   2
//         7   5   2   2

#include <iostream>
#define ll long long int
#define mod 1000000009

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[100001][3];

int main() {
    FastIO();

    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1, dp[3][1] = 1, dp[3][2] = 1;

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        int n;
        cin >> n;

        for(int i = 4 ; i <= n ; i++){
            if(dp[i][0] == 0){
                dp[i][0] += dp[i - 1][1];
                dp[i][0] += dp[i - 1][2];
                dp[i][0] %= mod;
            }

            if(dp[i][1] == 0){
                dp[i][1] += dp[i - 2][0];
                dp[i][1] += dp[i - 2][2];
                dp[i][1] %= mod;
            }

            if(dp[i][2] == 0){
                dp[i][2] += dp[i - 3][0];
                dp[i][2] += dp[i - 3][1];
                dp[i][2] %= mod;
            }
        }

        ll ans = 0;
        for(int i = 0 ; i < 3 ; i++){
            ans += dp[n][i];
        }
        cout << ans % mod << '\n';
    }


    return 0;
}