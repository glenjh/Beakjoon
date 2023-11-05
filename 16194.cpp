#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[1001];
int arr[1001];

int main() {
    FastIO();

    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = min(arr[2], 2 * arr[1]);

    for(int i = 3 ; i <= n ; i++){
        dp[i] = min(arr[i], i * arr[1]);

        for(int j = 1 ; j < i ; j++){
            dp[i] = min(dp[i], arr[j] + dp[i-j]);
        }
    }
    
    cout << dp[n] << '\n';

    return 0;
}