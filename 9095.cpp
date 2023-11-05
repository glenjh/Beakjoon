#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int t;
    cin >> t;

    for(int testcase = 0 ; testcase < t; testcase++){
        int arr[12];
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        int input;
        cin >> input;

        for(int i = 4 ; i <= input ; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }

        cout << arr[input] << '\n';
    }

    return 0;
}