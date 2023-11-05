#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int l;
    long long sum = 0;
    string s;
    cin >> l;
    cin >> s;

    for(int i=0 ; i<s.length() ; i++){
        long a = 1;
        for(int j=0 ; j<i ; j++){
            a*= 31;
            a = a%1234567891;
        }
        sum += (s[i] - 96)%1234567891 * a%1234567891;
    }
    cout << sum%1234567891;
    return 0;
}