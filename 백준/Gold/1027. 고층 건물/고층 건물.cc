#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[51];
int cnt[51];

int main() {
    FastIO();

    int n, ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        double M = INT_MIN;
        for(int j = i + 1 ; j < n ; j++){
            double t = (double)(arr[j] - arr[i]) / (j - i);
            if(t > M){
                M = t;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        ans = max(ans, cnt[i]);
    }

    cout << ans << '\n';

    return 0;
}