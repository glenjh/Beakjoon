#include <iostream>
#include <vector>
#define ll unsigned long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll n, q;
vector<bool> visited;
vector<ll> p;

int main() {
    FastIO();

    cin >> n >> q;
    for(ll i = 0 ; i <= n ; i++){
        visited.push_back(false);
    }

    for(ll i = 0 ; i < q ; i++){
        ll input, answer = 0;
        bool flag = true;
        cin >> input;

        int temp = input;

        while(temp > 1){
            if(visited[temp]){
                flag = false;
                answer = temp;
            }
            temp /= 2;
        }
        if(flag){
            visited[input] = true;
        }
        p.push_back(answer);
    }

    for(auto it : p){
        cout << it << '\n';
    }

    return 0;
}