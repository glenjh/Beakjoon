#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int e, s, m, ans = 0;
    cin >> e >> s >> m;

    int a = 0, b = 0, c = 0;
    while(true){
        if(a == e && b == s && c == m){ break; }
        a += 1;
        b += 1;
        c += 1;
        ans++;

        if(a > 15){ a = 1; }
        if(b > 28){ b = 1; }
        if(c > 19){ c = 1; }
    }

    cout << ans << '\n';

    return 0;
}