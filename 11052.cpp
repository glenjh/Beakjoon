#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = max( (dp[1] + arr[1]), (arr[2]));

    for(int i = 3 ; i <= n ; i++){
        
        for(int j = 1 ; j <= i ; j++){
            dp[i] = max(dp[i], arr[j] + dp[i-j]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}