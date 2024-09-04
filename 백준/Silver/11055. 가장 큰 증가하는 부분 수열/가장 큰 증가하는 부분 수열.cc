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

    int n, answer = 0;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        dp[i] = arr[i];
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}