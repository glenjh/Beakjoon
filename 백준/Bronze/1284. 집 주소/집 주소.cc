#include<iostream>
#include <string>
using namespace std;


int main() {
    int n;
    int sum;
    int space;
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        string s = to_string(n);
        sum = s.length() + 1;
        for (int i = 0; i < s.length(); i++) {
            
            if (s[i] == '1') {
                sum += 2;
                
            }else if (s[i] == '0') {
                sum += 4;   
            }
            else {
                sum += 3;
            }
       }
        cout << sum<<endl;
    }

    return 0;
}