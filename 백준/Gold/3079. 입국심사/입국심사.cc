#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    ll n, m, answer;
    vector<ll> v;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    ll l = 0, r = m * v[n - 1], mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll cnt = 0;

        for(ll i = 0 ; i < n ; i++){
            cnt += mid / v[i];
        }

        if(cnt >= m){
            answer = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}