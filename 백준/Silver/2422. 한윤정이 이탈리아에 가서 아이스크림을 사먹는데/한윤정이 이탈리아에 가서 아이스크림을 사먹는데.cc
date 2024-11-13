#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check[201][201];

int main() {
    FastIO();

    int n, m, ans = 0;
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        check[a][b] = true;
        check[b][a] = true;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            if(check[i][j]){ continue; }
            for(int k = j + 1 ; k <= n ; k++){
                if(check[i][k] || check[j][k]){ continue; }
                ans += 1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}