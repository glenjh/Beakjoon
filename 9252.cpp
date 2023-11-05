#include <iostream>
#include <string>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX][MAX];
int chk[MAX][MAX];

string a, b;

void LCS(string a, string b){
    for(int i = 0 ; i <= a.length() ; i++){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= b.length() ; i++){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= a.length() ; i++){
        for(int j = 1 ; j <= b.length() ; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                chk[i][j] = 0;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if(dp[i][j] == dp[i][j - 1]){
                    chk[i][j] = 1;
                }
                else{
                    chk[i][j] = 2;
                }
            }
        }
    }
}

void Print(int i, int j){
    if(i == 0 || j == 0){ return; }

    if(chk[i][j] == 0){
        Print(i - 1, j - 1);
        cout << a[i - 1];
    }
    else if(chk[i][j] == 1){
        Print(i, j - 1);
    }
    else{
        Print(i - 1, j);
    }
}

int main() {
    FastIO();

    cin >> a >> b;

    LCS(a, b);
    cout << dp[a.length()][b.length()] << '\n';
    Print(a.length(), b.length());

    return 0;
}