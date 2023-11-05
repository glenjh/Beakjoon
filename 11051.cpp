#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[1001][1001];

void BinomialCoefficient(int n, int k){
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= min(i, k) ; j++){
            if(i == 0 || i == j){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i - 1][j] % 10007 + dp[i - 1][j - 1] % 10007;
            }
        }
    }
}

int main() {
    FastIO();

    int n, k;
    cin >> n >> k;
    BinomialCoefficient(n, k);
    cout << dp[n][k] % 10007 << '\n';

    return 0;
}