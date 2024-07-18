#include<iostream>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;

    int max = 1;
    int up = 6;
    int cnt = 1;

    while (1) {
        if (n <= max) {
            cout << cnt << endl;
            return 0;
        }
        max = max + up;
        cnt += 1;
        up += 6;
    }

    
}