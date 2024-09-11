#include <iostream>
#include <cmath>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[31];

int main() {
    FastIO();

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;

    for(int i = 5 ; i <= n ; i++){
        if(i % 2 == 1){
            dp[i] = 0;
        }
        else{
            dp[i] += dp[i - 2] * 3;
            for(int j = i - 4 ; j >= 2 ; j-=2){
                dp[i] += dp[j] * 2;
            }
            dp[i] += 2;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}