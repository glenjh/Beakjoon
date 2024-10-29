#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<ll> v;
    int n, ansL, ansR;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        ll input;
        cin >> input;
        v.push_back(input);
    }

    ll l = 0, r = v.size() - 1;
    ll sub = 2000000000;
    while(l < r){
        ll add = v[l] + v[r];
        if(abs(add) < sub){
            sub = abs(add);
            ansL = l;
            ansR = r;
        }

        if(add > 0){
            r--;
        }
        else if(add < 0){
            l++;
        }
        else if(add == 0){
            ansL = l;
            ansR = r;
            break;
        }
    }

    cout << v[ansL] << ' ' << v[ansR] << '\n';

    return 0;
}