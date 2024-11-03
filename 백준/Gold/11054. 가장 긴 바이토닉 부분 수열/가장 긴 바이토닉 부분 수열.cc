#include <iostream>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp1[1001];
int dp2[1001];
int arr[1001];

int main() {
    FastIO();

    int n, ans = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = n - 1 ; j > i ; j--){
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        ans = max(ans, dp1[i] + dp2[i]);
    }
    if(ans != 0){
        ans += 1;
    }
    else{
        ans = 1;
    }

    cout << ans << '\n';

    return 0;
}