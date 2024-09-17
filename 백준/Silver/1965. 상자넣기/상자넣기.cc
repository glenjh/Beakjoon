#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[1001];

int main() {
    FastIO();

    int n, answer = 0;
    int arr[1001];
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }
    
    dp[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] == 0){
                dp[i] = 1;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';

    return 0;
}