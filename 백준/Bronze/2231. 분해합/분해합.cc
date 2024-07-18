#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

 
int main(){
    int n;
    
    cin >> n;
    for(int i=1 ; i<n ; i++){
        int sum = 0;
        sum += i;
        int j=i;
        while(j>0){
            sum += j%10;
            j = j/10;
        }
        if(sum == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}