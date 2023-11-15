#include <iostream>
#define MAX 10000001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX];

int main() {
    FastIO();
    
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 3 ; i <= n ; i++){
        dp[i] = (dp[i - 1]  + dp[i - 2]) % 10;
    }

    cout << dp[n] << '\n';

    return 0;
}