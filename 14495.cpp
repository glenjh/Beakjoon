#include <iostream>

using namespace std;

long arr[117] = {0,1,1,1,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    for(int i = 4 ; i < 117 ; i++){
        arr[i] = arr[i - 1] + arr[i - 3];
    }
    cout << arr[n];
    return 0;
}