#include <iostream>
#include <vector>
using namespace std;

int arr[1000000];

void self_num(int a){
    int sum = a;
    while(a != 0){
        sum += a%10;
        a = a/10;
    }
    arr[sum] = sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    for(int i=1 ; i<=10000 ; i++){
        self_num(i);
    }

    for(int i=1 ; i<=10000 ; i++){
        if(arr[i] == 0){
            cout << i << '\n';
        }
    }
    return 0;
}