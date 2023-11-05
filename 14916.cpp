#include <iostream>
using namespace std;

int main(){
    int n, two, five;
    cin >> n;

    five = n / 5;

    if( (n % 5) % 2 != 0 ){
        five -= 1;
        if(five < 1){ five = 0; }
    }

    if((n - (five*5)) % 2 != 0){
        cout << -1;
        return 0; 
    }

    two = (n - (five*5)) / 2;

    cout << two + five;
    return 0;
}