#include <iostream>
using namespace std;

int main(){
    long n;
    int cnt=0;
    int num = 1;
    long sum = 0;
    cin >> n;

    while(true){
        sum += num;
        cnt++;
        if(sum > n){
            cnt--;
            break;
        }
        num++;
    }
    cout << cnt;
    return 0;
}