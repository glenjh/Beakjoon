#include <iostream>

using namespace std;

long long arr[81] = {0,1,1,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 3 ; i <= n+1 ; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << 2 * (arr[n] + arr[n+1]);
    return 0;
}