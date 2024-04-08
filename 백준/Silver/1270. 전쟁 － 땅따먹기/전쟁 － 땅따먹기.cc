#include <iostream>
#include <unordered_map>
#define ll long long

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        unordered_map<ll, ll> m;
        ll t, half, num;
        ll M = -1;
        cin >> t;
        half = t / 2;
        for(int j = 0 ; j < t ; j++){
            ll input;
            cin >> input;
            m[input] += 1;
        }

        for(auto it : m){
            if(it.second > M){
                M = it.second;
                num = it.first;
            }
        }
        if(M > half){
            cout << num << '\n';
        }
        else{
            cout << "SYJKGW" << '\n';
        }
    }

    return 0;
}