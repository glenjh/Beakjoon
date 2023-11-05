#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(true){
        bool prime[3000000] = {false, };
        
        prime[0] = true;
        prime[1] = true;

        cin >> n;
        int cnt = 0;

        if(n == 0) break;

        for(int i=2 ; i<=sqrt(2*n) ; i++){
            if(prime[i] == false){
                for(int j=i+i ; j<=2*n ; j+=i){
                    prime[j] = true;
                }
            }
        }
        for(int i=n+1 ; i<=2*n ; i++){
            if(prime[i] == false){ cnt++; }
        }
        cout << cnt << '\n';
    }
    return 0;
}
