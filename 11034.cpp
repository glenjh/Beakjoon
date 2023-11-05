#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        cout << max(b-a-1 , c-b-1) << '\n';
    }
    return 0;
}