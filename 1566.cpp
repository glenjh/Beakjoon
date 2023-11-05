#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int start = 1;
    while(true){
        if(start + start*start == n -1){
            break;
        }
        start++;
    }

    cout << start << '\n';

    return 0;
}