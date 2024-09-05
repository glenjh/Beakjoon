#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[101][101];
ll dp[101][101];
int n, answer;

void DP(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j + arr[i][j] < n && j != n - 1){
                dp[i][j + arr[i][j]] += dp[i][j];
            }

            if(i + arr[i][j] < n && i != n - 1){
                dp[i + arr[i][j]][j] += dp[i][j];
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1;
    DP();

    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}