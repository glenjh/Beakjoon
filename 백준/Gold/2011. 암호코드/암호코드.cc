#include <iostream>
#include <string>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[5001];

int main() {
    FastIO();

    string s;
    cin >> s;
    
    dp[0] = 1;
    if(s[0] == '0'){
        dp[1] = 0;
    }else{
        dp[1] = 1;
    }

    for(ll i = 2 ; i <= s.length() ; i++){
        ll curr = s[i - 1] - '0', tempInt = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if(curr == 0){
            if(10 <= tempInt && tempInt <= 26){
                dp[i] += dp[i - 2];
            }
        }

        if(1 <= curr && curr <= 9){
            dp[i] += dp[i - 1];

            if(10 <= tempInt && tempInt <= 26){
                dp[i] += dp[i - 2];
            } 
        }
        dp[i] %= 1000000;
    } 

    cout << dp[s.length()] % 1000000 << '\n';

    return 0;
}

