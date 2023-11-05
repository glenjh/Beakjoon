#include <iostream>

using namespace std;

int arr[301];
int dp[301];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int n, answer;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max( (arr[1] + arr[3]), (arr[2] + arr[3]) );

    for(int i = 4 ; i <= n ; i++){
        dp[i] = max( (dp[i-3] + arr[i-1] + arr[i]), (dp[i-2] + arr[i]) );
    }

    answer = dp[n];
    cout << answer << '\n';

    return 0;
}