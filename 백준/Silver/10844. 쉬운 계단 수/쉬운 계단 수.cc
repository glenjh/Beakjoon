#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[105][10];

int main() {
    FastIO();

    ll n, answer = 0;
    cin >> n;

    for(int i = 1 ; i < 10 ; i++){
        dp[1][i] = 1;
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(j - 1 >= 0){
                dp[i][j] += dp[i - 1][j - 1]; 
            }

            if(j + 1 < 10){
                dp[i][j] += dp[i - 1][j + 1];
            }

            dp[i][j] %= 1000000000;
        }
    }

    for(int i = 0 ; i < 10 ; i++){
        answer += dp[n][i];
    }
    cout << answer % 1000000000 << '\n';

    return 0;
}