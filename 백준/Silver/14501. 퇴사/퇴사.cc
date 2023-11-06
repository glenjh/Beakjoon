#include <iostream>
#define MAX 16

using namespace std;

int dp[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, answer = 0;
    int T[MAX];
    int P[MAX];
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> T[i] >> P[i];
    }

    for(int i = n ; i >= 1 ; i--){
        if(T[i] + i > n + 1){
            dp[i] = dp[i + 1];
        }
        else{
            dp[i] = max(dp[i + 1], dp[T[i] + i] + P[i]);
        }
    }

    cout << dp[1] << '\n'; 

    return 0;
}