#include <iostream>
#include <string>

using namespace std;

int main() {
    int max = 0;
    int max_idx = 0;
    int max_cnt = 0;

    int cnt[26] = { 0 };
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
        cnt[str.find(s[i])]++;
    }
    for (int i = 0; i < 26; i++) {
        if (max < cnt[i]) {
            max = cnt[i];
            max_idx = i;
        }
    }
   
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == max) {
            max_cnt++;
        }
    }
    if (max_cnt == 1) {
        cout << str[max_idx];
    }
    else {
        cout << "?";
    }
    
    
    return 0;
}