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
vector<ll> wantList;
vector<ll> p;

void Sol(ll a, ll origin){
    ll block;
    bool flag = true;

    while(p[a] != 1){
        a = p[a];

        if (visited[a]){
            block = a;
            flag = false;
            // break;
        }
    }

    if(flag){
        visited[origin] = true;
        cout << 0 << '\n';
    }else{
        cout << block << '\n';
    }
}

int main() {
    FastIO();

    cin >> n >> q;
    for(ll i = 0 ; i <= n ; i++){
        // p.push_back(i + 1);
        visited.push_back(false);
    }

    for(ll i = 0 ; i < q ; i++){
        ll input, answer = 0;
        cin >> input;
        // wantList.push_back(input);

        int temp = input;

        while(temp > 1){
            if(visited[temp]){
                answer = temp;
            }
            temp /= 2;
        }
        visited[input] = true;
        p.push_back(answer);
    }

    for(auto it : p){
        cout << it << '\n';
    }

    // for(ll i = 1 ; i <= n ; i++){
    //     p[i] = i / 2;
    // }

    // for(ll i = 0 ; i < q ; i++){
    //     Sol(wantList[i], wantList[i]);
    // }

    return 0;
}