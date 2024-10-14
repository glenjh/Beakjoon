#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        int p, ans = 0, idx;
        int arr[20];
        cin >> p;

        for(int i = 0 ; i < 20 ; i++){
            idx = i;
            int input;
            cin >> input;
            arr[i] = input;

            for(int j = i ; j > 0 ; j--){
                if(arr[j - 1] > arr[j]){
                    swap(arr[j], arr[j - 1]);
                    ans += 1;
                }
            }
        }
        cout << p << ' ' << ans << '\n';
    }

    return 0;
}