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

    for(int testcase = 0 ; testcase < t ; testcase++){
        long long arr0[41];
        long long arr1[41];

        int n;
        cin >> n;

        arr0[0] = 1, arr0[1] = 0;
        arr1[0] = 0, arr1[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            arr0[i] = arr0[i-1] + arr0[i-2];
            arr1[i] = arr1[i-1] + arr1[i-2];
        }

        cout << arr0[n] << ' ' << arr1[n] << '\n';
    }

    return 0;
}