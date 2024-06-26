#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int a;
    int b;
    
    

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        int cnt = 1;
        for (int j = 0; j < b; j++) {
            cnt = (cnt * a) % 10;
        }
        if (cnt == 0) {
            cout << 10 << endl;
        }
        else {
            cout << cnt << endl;
        }
    }


    return 0;
}