#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 1;
    
    string s;
    
    getline(cin, s, '\n');
    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i]) != 0) {
            cnt += 1;
        }
    }
    if (s[0] == ' ') {
        cnt -= 1;
    }
    if (s[s.length() - 1] == ' ') {
        cnt -= 1;
    }

    cout << cnt;
    
    return 0;
}