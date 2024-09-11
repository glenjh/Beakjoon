#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll arr[1025][1025];
ll dp[1025][1025];

int main() {
    FastIO();

    int n, m;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == 1){
                dp[i][j] = arr[i][j];
            }
            else{
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2 && y1 == y2){
            cout << arr[x1][y1] << '\n';
        }
        else{
            int ans = 0;
            for(int i = x1 ; i <= x2 ; i++){
                ans += dp[i][y2] - dp[i][y1 - 1];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}