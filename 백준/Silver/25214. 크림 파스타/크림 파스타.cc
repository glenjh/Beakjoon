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

    int n, mm = 0 ,MM = 0, localSub;
    int arr[MAX];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int temp1 = 0, temp2 = 0, temp3;
        cin >> arr[i];
        
        if(i == 0){
            dp[i] = 0;
            mm = arr[i];
            MM = arr[i];
        }
        else{
            if(arr[i] < mm){
                mm = arr[i];
                dp[i] = dp[i - 1];
            }
            else{
                if(arr[i] > MM){
                    temp1 = arr[i] - MM;
                    MM = arr[i];
                }
                temp2 = arr[i] - mm;
                temp3 = max(temp1, temp2);
                if(temp3 < dp[i - 1]){
                    dp[i] = dp[i - 1];
                }
                else{
                    dp[i] = temp3;
                }
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << dp[i] << ' ';
    }

    return 0;
}