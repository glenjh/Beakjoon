#include <iostream>
#define MAX 101

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX];

int main() {
    FastIO();

    int n;
    int gain[MAX], loose[MAX];
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> loose[i];
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> gain[i];
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 100 ; j > loose[i] ; j--){
            dp[j] = max(dp[j - loose[i]] + gain[i], dp[j]);
        }
    }

    int answer = 0;
    for(int i = 1 ; i < MAX ; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}