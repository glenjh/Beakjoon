#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    bool flag = true;
    string input;
    cin >> input;
    int len = input.length();

    for(int i = 0 ; i < len / 2 ; i++){
        if(input[i] != input[len-i-1]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}