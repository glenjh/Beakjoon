#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    int none = 26;

    int cnt[26] = { 0 };

    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cnt[name[0]-97] += 1;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << char(i + 97);
        }
        else {
            none--;
        }
    }

    if (none <=0) {
        cout << "PREDAJA";
    }

    return 0;
}