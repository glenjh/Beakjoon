#include <iostream>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int t;
    cin >> t;
    for(int testCase = 0 ; testCase < t ; testCase++){
        int n;
        int arr[MAX];
        int dp[MAX];
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            dp[i] = 0;
        }

        int local = 0, MM = -1001;
        for(int i = 0 ; i < n ; i++){
            local += arr[i];
            if(local > MM){
                MM = local;
            }
            if(local < 0){
                local = 0;
            }
        }

        cout << MM << '\n';
    }

    return 0;
}