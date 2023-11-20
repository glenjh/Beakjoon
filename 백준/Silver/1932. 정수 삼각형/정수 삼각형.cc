#include <iostream>
#define MAX 501

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
    FastIO();

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= i + 1 ; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][1] = arr[0][1];
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j <= i + 1 ; j++){
            if(j == 1){
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else if(j == i + 1){
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j]; 
            }
            else{
                dp[i][j] = max(arr[i][j] + dp[i - 1][j - 1], arr[i][j] + dp[i - 1][j]);
            }
        }
    }

    int rel = 0;
    for(int i = 1 ; i <= n ; i++){
        rel = max(rel, dp[n - 1][i]);
    }

    cout << rel << '\n';

    return 0;
}