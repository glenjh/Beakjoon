#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin >> testcase;
    for(int i=0 ; i< testcase ; i++){
        int n;
        vector<int> v;
        bool prime[10001];
        for(int j=0 ; j<10001 ; j++){
            prime[j] = false;
        }
        prime[0] = prime[1] = true;

        cin >> n;
        for(int j=2 ; j<sqrt(n) ; j++){
            if(prime[j] == false){
                for(int k= j+j ; k<=n ; k+=j){
                    prime[k] = true;
                }
            }
        }

        for(int j=0 ; j<=n ; j++){
            if(prime[j] == false){ v.push_back(j); }
        }
        int sub;
        int ret = 10000;
        int a, b;

        for(int j=0 ; j<v.size() ; j++){
            for(int k=j ; k<v.size() ; k++){
                if(v[j] + v[k] == n){
                    sub = v[k] - v[j];
                    if(ret > sub){
                        ret = sub;
                        a = v[k];
                        b = v[j];
                    }
                }
            }
        }
        cout << b << ' ' << a << '\n';
    }
    return 0;
}