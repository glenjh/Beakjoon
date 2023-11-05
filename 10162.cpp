#include <iostream>
using namespace std;

int main(){
    int t, count_300 = 0, count_60 = 0, count_10 = 0;
    cin >> t;
    if(t%10 != 0){ cout << -1; return 0; }

    else{
        count_300 = t/300;
        t -= count_300 * 300;

        count_60 = t/60;
        t -=  count_60 * 60;

        count_10 = t/10;
        t -= count_10 * 10;

        cout << count_300 << " " << count_60 << " " << count_10;
    }

    return 0;
}