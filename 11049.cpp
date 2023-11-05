#include <iostream>
#include <climits>
#define MAX 501

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX][MAX];
int arr[MAX][2];

void ChainedMatrixMul(int n){
    for(int i = 1 ; i <= n ; i++){
        dp[i][i] = 0;
    }

    for(int diagonal = 1 ; diagonal < n ; diagonal++){ //몇개의 행렬을 곱할지
        for(int i = 1 ; i <= n - diagonal ; i++){
            int j = i + diagonal;
            dp[i][j] = INT_MAX;
            for(int k = i ; k < j ; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1]);
            }   
        }
    }
}

int main() {
    FastIO();

    int n;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    ChainedMatrixMul(n);
    cout << dp[1][n] << '\n';

    return 0;
}