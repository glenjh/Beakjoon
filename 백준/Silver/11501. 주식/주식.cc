#include <iostream>
#define ll long long

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();
    
    ll testCase;
    cin >> testCase;

    for(ll t = 0 ; t < testCase ; t++){
        ll n; 
        ll arr[1000001];
        ll ans = 0;
        cin >> n;

        for(ll i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        int M = arr[n - 1];
        for(ll i = n - 2 ; i >= 0 ; i--){
            if(arr[i] > M){
                M = arr[i];
            }
            else{
                ans += M - arr[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}