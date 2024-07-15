#include <iostream>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[100001][3];
int temp[6];
int dp[6];

int main() {
    FastIO();

    int n, m = 0, M = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    dp[0] = arr[0][0], dp[3] = arr[0][0];
    dp[1] = arr[0][1], dp[4] = arr[0][1];
    dp[2] = arr[0][2], dp[5] = arr[0][2];

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < 6 ; j++){
            temp[j] = dp[j]; 
        }

        dp[0] = arr[i][0] + max( temp[0], temp[1] );
        dp[1] = arr[i][1] + max( {temp[0], temp[1], temp[2]} );
        dp[2] = arr[i][2] + max( temp[1], temp[2]);

        dp[3] = arr[i][0] + min(temp[3], temp[4]);
        dp[4] = arr[i][1] + min({temp[3], temp[4], temp[5]});
        dp[5] = arr[i][2] + min(temp[4], temp[5]);
    }

    M = max({ dp[0], dp[1], dp[2] });
    m = min({ dp[3], dp[4], dp[5] });
    cout << M << ' ' << m << '\n';

    return 0;
}