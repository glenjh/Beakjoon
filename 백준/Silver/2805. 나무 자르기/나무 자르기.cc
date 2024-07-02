#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, m;
    vector<ll> v;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        ll input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    ll l = 0, r = v[n - 1], mid, answer;
    while(l <= r){
        mid = (l + r) / 2;
        ll sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(mid < v[i]){
                sum += v[i] - mid;
            }
        }

        if(sum >= m){
            answer = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << answer << '\n';

    return 0;
}