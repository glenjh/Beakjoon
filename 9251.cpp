#include <iostream>
#include <string>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dp[MAX][MAX] = {0, };
int s[MAX][MAX] = {0, };

void LCS(string a, string b){
    for(int i = 0 ; i <= a.length() ; i++){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i < b.length() ; i++){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= a.length() ; i++){
        for(int j = 1 ; j <= b.length() ; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                s[i][j] = 0;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i][j] == dp[i][j - 1]){
                    s[i][j] = 1;
                }
                else{
                    s[i][j] = 2;
                }
            }
        }
    }
}

void Print(string a, string b, int aLen, int bLen){
    if(aLen == 0 || bLen == 0){
        return;
    }

    if(s[aLen][bLen] == 0){
        Print(a, b, aLen - 1, bLen - 1);
        cout << a[aLen - 1];
    }
    else if(s[aLen][bLen] == 1){
        Print(a, b, aLen, bLen - 1);
    }
    else{
        Print(a, b, aLen - 1, bLen);
    }
}   

int main() {
    FastIO();

    string a, b;
    cin >> a >> b;
    LCS(a, b);
    cout << dp[a.length()][b.length()] << '\n';
    // Print(a, b, a.length(), b.length());

    return 0;
}