#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[101][25];
int arr[101];

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[1][arr[1]] = 1;

    for(int i = 2 ; i < n ; i++){
        for(int j = 0 ; j <= 20 ; j++){
            if(j - arr[i] >= 0){
                dp[i][j - arr[i]] += dp[i - 1][j];
            }

            if(j + arr[i] <= 20){
                dp[i][j + arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 1][arr[n]] << '\n';

    return 0;
}