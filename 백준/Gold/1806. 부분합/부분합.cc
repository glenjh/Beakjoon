#include <iostream>
#include <climits>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[100001];

int main() {
    FastIO();

    int n, s;
    int ans = INT_MAX;
    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int sum = arr[l];
    while(r < n){
        if(sum >= s){
            ans = min(ans, r - l + 1);
            sum -= arr[l];
            l++;
        }
        else{
            r++;
            sum += arr[r];
        }
    }

    if(ans == INT_MAX){
        ans = 0;
    }

    cout << ans << '\n';

    return 0;
}