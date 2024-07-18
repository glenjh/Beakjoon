#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int a, b, c;
    string temp = "";
    cin >> a >> b >> c;

    cout << a + b - c << '\n';
    
    temp += to_string(a);
    temp += to_string(b);

    cout << stoi(temp) - c << '\n';

    return 0;
}