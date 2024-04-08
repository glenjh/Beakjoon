#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    set<string> s;
    map<string, double> m;
    ll total = 0;

    while(true){
        string input;
        getline(cin, input);

        if(input == ""){ break; }
        else{
            total += 1;

            m[input] += 1;
            s.insert(input);
        }   
    }

    cout << fixed;
    cout.precision(4);

    for(auto it : s){
        cout << it << ' ' << (m[it] / total) * 100 << '\n';
    }

    return 0;
}