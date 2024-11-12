#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<int> v;
    int n, a, b;
    cin >> n >> a >> b;

    if(a + b > n + 1){
        cout << -1 << '\n';
    }
    else{
        for(int i = 1 ; i < a ; i++){
            v.push_back(i);
            if(v.size() == 1){
                for(int j = 0 ; j <= n - (a + b) ; j++){
                    v.push_back(1);
                }
            }
        }

        int M = max(a, b);
        v.push_back(M);

        if (v.size() == 1){
            for (int j = 0; j <= n - (a + b); j++){
                v.push_back(1);
            }
        }

        for(int i = b - 1 ; i >= 1 ; i--){
            v.push_back(i);
        }
    }

    for(auto it : v){
        cout << it << ' ';
    }

    return 0;
}