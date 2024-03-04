#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    string answer = "";
    ll n;
    cin >> n;

    unordered_map<string, ll> m;

    for(ll i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        m[input] += 1;
    }

    for(ll i = 0 ; i < n - 1 ; i++){
        string input;
        cin >> input;
        m[input] -= 1;
        
    }

    for (auto it : m){
        if(it.second > 0){
            answer = it.first;
        }
    }

    cout << answer << '\n';

    return 0;
}