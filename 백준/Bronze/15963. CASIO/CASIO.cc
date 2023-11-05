#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    long long a, b;
    cin >> a >> b;

    if(a == b){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}