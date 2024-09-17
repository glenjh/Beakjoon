#include <iostream>
#define ll long long int
#define mod 1000000009

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[1000001];

int main() {
    FastIO();

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        int n;
        cin >> n;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(ll i = 4 ; i <= n ; i++){
            if(dp[i] == 0){
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
                dp[i] %= mod;
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}