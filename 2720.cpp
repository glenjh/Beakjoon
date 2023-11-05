#include <iostream>

using namespace std;

int main(){
    int t , amount, Q, D, N, P;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        Q = 0, D = 0, N = 0, P = 0;
        cin >> amount;

        Q = amount / 25;
        amount -= Q * 25;

        D = amount / 10;
        amount -= D * 10;

        N = amount / 5;
        amount -= N * 5;

        P = amount / 1;
        amount -= P * 1;

        cout << Q << " " << D << " " << N << " " << P << endl;
    }
    return 0;
}