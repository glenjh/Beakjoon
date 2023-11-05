#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, r;
    cin >> t;
    
    for(int i = 0 ; i < t ; i++){
        cin >> r >> n;
        int mod = 1, temp = 1;
        for(int i = n ; i > (n-r) ; i--){
            temp *= i;
            temp /= mod++;
        }
        cout << temp << '\n';
    }
    return 0;
}