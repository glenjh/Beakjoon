#include <iostream>

using namespace std;

int main() {
    int cnt = 99;
    int n;
    cin >> n;

    

    if (n < 100) {
        cnt = n;
    }
    else {
        for (int i = 100; i <= n; i++) {
            if (((i % 10) - (i / 10) % 10) == (i / 10) % 10 - (i / 10) / 10) {
                cnt += 1;
            }
        }
        
    }
    cout << cnt;
    return 0;
}