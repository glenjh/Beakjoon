#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int m, n;
    cin >> m >> n;

    int start = sqrt(m), sum = 0;

    while(true){
        if(start * start > n){ break; }
        if(m <= start * start && start * start <= n){
            v.push_back(start*start);
        }
        start++;
    }

    if(v.size() == 0){
        cout << -1 << '\n';
        return 0;
    }

    for(auto it : v){
        sum += it;
    }
    cout << sum << '\n';
    cout << v[0] << '\n';
    return 0;
}