#include<iostream>
#include <string>
using namespace std;


int main() {
    int n;
    while (true) {
        
        cin >> n;
        if (n == 0) {
            break;
        }
        string s = to_string(n);
        string r_s;
        for (int i = s.length() - 1; i >= 0; i--) {
            r_s += s[i];
        }
       
        if (stoi(s) == stoi(r_s)) {
            cout << "yes"<<endl;
        }
        else {
            cout << "no"<<endl;
        }
        
    }

    return 0;
}