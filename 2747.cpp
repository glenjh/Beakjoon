#include <iostream>

using namespace std;

int dp[46] = {0, 1, 1,};

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 3; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}