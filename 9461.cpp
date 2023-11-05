#include <iostream>

using namespace std;

long long dp[101] = {0,1,1,1,2,2,};

int main(){
    int n, t;

    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> n;

        if(n <= 5){
            cout << dp[n] << '\n';
        }else{
            for(int i = 5 ; i <= n ; i++){
                dp[i] = dp[i-1] + dp[i-5];
            }
            cout << dp[n] << '\n';
        }

    }
    return 0;
}