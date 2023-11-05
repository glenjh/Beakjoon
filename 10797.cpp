#include <iostream>

using namespace std;

int main(){
    int n, input, cnt = 0;
    cin >> n;
    for(int i = 0 ; i < 5 ; i++){
        cin >> input;
        if(input % 10 == n){ cnt+=1; } 
    }
    cout << cnt;
    return 0;
}