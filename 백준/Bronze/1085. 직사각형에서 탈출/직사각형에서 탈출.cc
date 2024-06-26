#include<iostream>
#include <string>
using namespace std;

int main() {
    int x, y, w, h;
    int len[4];
    cin >> x >> y >> w >> h;

    len[0] = x;
    len[1] = y;
    len[2] = w - x;
    len[3] = h - y;

    int min = 1001;

    for (int i = 0; i < 4; i++) {
        if (min > len[i]) {
            min = len[i];
        }
    }
    cout << min;



    return 0;
}