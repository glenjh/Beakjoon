#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    bool submit[31] = {false, };

    for(int i = 0 ; i < 28 ; i++){
        int input;
        cin >> input;
        submit[input] = true;
    }

    for(int i = 1 ; i < 31 ; i++){
        if(!submit[i]){
            cout << i << '\n';
        }
    }
    return 0;
}