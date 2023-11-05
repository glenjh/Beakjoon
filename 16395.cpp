#include <iostream>

using namespace std;

int main(){
    int n, k, rel = 1 , mod = 1;
    cin >> n >> k;

    for(int i = n-1 ; i >= n-k+1  ; i--){
        rel *= i;
        rel /= mod++;
    }
    cout << rel;
    return 0;
}