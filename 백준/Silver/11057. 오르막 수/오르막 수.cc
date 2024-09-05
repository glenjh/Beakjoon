#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[1001][10]; // dp[i][j] = 길이가 i인데, 마지막 숫자가 j인 경우 가능한 갯수

int main() {
    FastIO();

    int n, answer = 0;
    cin >> n;

    for(int i = 0 ; i < 10 ; i++){
        dp[1][i] = 1;
    }
    
    for(int i = 2 ; i <= n ; i++){
        dp[i][0] = 1;
        for(int j = 1 ; j < 10 ; j++){
            dp[i][j] = (dp[i - 1][j] % 10007) + (dp[i][j - 1] % 10007);
        }
    }

    for(int i = 0 ; i < 10 ; i++){
        answer += dp[n][i];
    }
    cout << answer % 10007 << '\n';

    return 0;
}