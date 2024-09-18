#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[50001];

int main() {
    FastIO();

    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        dp[i] = i;
    }

    for(int i = 4 ; i <= n ; i++){
        for(int j = 1 ; j <= i / 2 ; j++){
            if(j * j <= i){ 
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}