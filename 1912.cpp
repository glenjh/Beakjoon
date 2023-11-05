#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, localSum = 0, maxSum = -1001;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;

        localSum += input;
        if(localSum > maxSum){
            maxSum = localSum;
        }
        if(localSum < 0){
            localSum = 0;
        }
    }
    cout << maxSum;

    return 0;
}