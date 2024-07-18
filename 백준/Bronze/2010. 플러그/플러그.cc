#include<iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int plug;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> plug;
        sum += plug;
    }
    sum = sum - (n - 1);
    cout << sum;
    return 0;
}