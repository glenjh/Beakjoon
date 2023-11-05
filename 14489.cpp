#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b;
    cin >> c;

    if(a + b >= 2*c){
        cout << a+b - 2*c << '\n';
    }else{
        cout << a + b << '\n';
    }
}