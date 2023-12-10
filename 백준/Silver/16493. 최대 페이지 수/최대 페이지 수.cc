#include <iostream>
#include <vector>
#define MAX 400

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX][MAX];

int main() {
    FastIO();

    vector<pair<int, int>> v;
    v.push_back({0, 0});
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int day, page;
        cin >> day >> page;
        v.push_back({day, page});
    }

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j >= v[i].first){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[m][n] << '\n';

    return 0;
}