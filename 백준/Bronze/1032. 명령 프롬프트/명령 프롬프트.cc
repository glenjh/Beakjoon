#include<iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string *filename = new string[n];
    char c;
    
    for (int i = 0; i < n; i++) {
        cin >> filename[i];
    }
    for (int i = 0; i < filename[0].length(); i++) {
        c = filename[0][i];
        for (int j = 0; j < n; j++) {
            if (c != filename[j][i]) {
                c = '?';
            }
        }
        cout << c;
    }

    return 0;
}