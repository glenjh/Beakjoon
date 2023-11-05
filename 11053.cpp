#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    vector<int> v;
    for(int i = 0 ; i < 1001 ; i++){
        dp[i] = 1;
    }
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    int answer = 0;
    for(int i = 0 ; i < n ; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}