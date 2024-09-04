#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[100001];

int main() {
    FastIO();

    ll n;
    cin >> n;

    for(ll i = 0 ; i <= n ; i++){
        dp[i] = i;
    }

    for(ll i = 4 ; i <= n ; i++){
        for(ll j = 1 ; j <= i / 2 ; j++){
            if(j * j <= i){
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}