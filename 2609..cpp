#include <iostream>
using namespace std;

int main(){
    int a,b;
    int x;
    cin >> a >> b;
    if(b > a){
        swap(a,b);
    }
    for(int i=b ; i>=1 ; i--){
        if(a%i == 0 && b%i == 0){
            x = i;
            break;
        }
    }
    cout << x << endl;
    cout << (a*b) / x;
    return 0;
}