#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = n;
    string s;
    
    string* arr = new string[n];
    for (int i = 0; i < n; i++) {
        bool ck = true;
        cin >> s;
        if (s.length() <= 2) {
            cnt += 0;
        }
        else {
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != s[j + 1]) {
                    for (int k = j + 1; k < s.length(); k++) {
                        if (s[j] == s[k]) {
                            cnt--;
                            goto end;
                        }
                    }
                }
            }
        }
    end:;
    }
    cout << cnt;

    return 0;
}