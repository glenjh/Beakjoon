#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    string origin;
    int n, ans = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        vector<int> alpha(26, 0);
        vector<int> s(26, 0);
        vector<int> v;

        string input;
        cin >> input;

        if(i == 0){
            origin = input;
        }
        else{
            for(int j = 0 ; j < origin.length() ; j++){
                alpha[origin[j] - 'A'] += 1;
            }

            for(int j = 0 ; j < input.length() ; j++){
                s[input[j] - 'A'] += 1;
            }

            for(int i = 0 ; i < 26 ; i++){
                if(alpha[i] != s[i]){
                    v.push_back(alpha[i] - s[i]);
                }
            }

            if(v.empty()){
                ans += 1;
            }
            else if(v.size() == 1 && abs(v[0]) == 1){
                ans += 1;
            }
            else if(v.size() == 2 && abs(v[0]) == 1 && v[0] + v[1] == 0){
                ans += 1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}