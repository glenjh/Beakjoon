#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[201];
int dp[201];

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        dp[i] = 1;
        cin >> arr[i];
    }

    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int M = -1;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] > M){
            M = dp[i];
        }
    }

    cout << n - M << '\n';

    return 0;
}