#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dp[10001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string bigSum(string a, string b){ // a가 더 짧음 b가 더 긴것
    string temp = "";
    int carry = 0, add = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.length() < b.length()){
        a += "0";
    }
    
    for(int i = 0 ; i < a.length() ; i++){
        add = (a[i]-'0') + (b[i]-'0') + carry;

        if(add >= 10){
            carry = 1;
            add -= 10;
        }else{
            carry = 0;
        }

        temp += to_string(add);
    }

    if(carry != 0){
        temp += to_string(carry);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int main(){
    FastIO();

    dp[1] = "0";
    dp[2] = "1";
    
    int n;
    cin >> n;

    for(int i = 3 ; i <= n+1 ; i++){
        dp[i] = bigSum(dp[i-2], dp[i-1]);
    }

    for(int i = 0 ; i < dp[n+1].length() ; i++){
        cout << dp[n+1][i];
    }
    cout << '\n';

    return 0;
}