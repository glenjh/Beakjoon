#include <iostream>
#define MAX 200001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX];

int main() {
    FastIO();

    int n, mm = 0, minVal;
    int arr[MAX];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        
        if(i == 0){
            dp[i] = 0;
            minVal = arr[i];
        }
        else{
            if(arr[i] < minVal){
                minVal = arr[i];
            }
            dp[i] = max(dp[i - 1], arr[i] - minVal);
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << dp[i] << ' ';
    }

    return 0;
}