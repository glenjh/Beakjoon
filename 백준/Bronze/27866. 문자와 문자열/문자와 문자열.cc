#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    string s;
    int n;
    cin >> s >> n;
    cout << s[n - 1] << '\n';

    return 0;
}