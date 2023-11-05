#include <iostream>

using namespace std;

long dp[91] = {0, 1, 1,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n <= 2){
        cout << dp[n];
    }
    else{
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[n];
    }
    return 0;
}