#include <iostream>
#include <string>
#include <climits>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int ans = INT_MAX;

string ChangeAt(string s, int idx){
    if(s[idx] == '0'){
        s[idx] = '1';
        if(idx - 1 >= 0){
            if (s[idx - 1] == '0'){
                s[idx - 1] = '1';
            }
            else{
                s[idx - 1] = '0';
            }
        }

        if(idx + 1 < s.size()){
            if (s[idx + 1] == '0'){
                s[idx + 1] = '1';
            }
            else{
                s[idx + 1] = '0';
            }
        }
    }
    else if(s[idx] == '1'){
        s[idx] = '0';
        if (idx - 1 >= 0){
            if (s[idx - 1] == '0'){
                s[idx - 1] = '1';
            }
            else{
                s[idx - 1] = '0';
            }
        }

        if (idx + 1 < s.size()){
            if (s[idx + 1] == '0'){
                s[idx + 1] = '1';
            }
            else{
                s[idx + 1] = '0';
            }
        }
    }

    return s;
}

void Change(string s, string tar, bool flag){
    int cnt = 0;

    if(flag){
        s = ChangeAt(s, 0);
        cnt += 1;
    }

    for(int i = 1 ; i < s.size() ; i++){
        if(s[i - 1] != tar[i - 1]){
            s = ChangeAt(s, i);
            cnt += 1;
        }
    }

    if(s == tar){
        ans = min(ans, cnt);
    }
}

int main() {
    FastIO();

    int n;
    string curr, target;

    cin >> n >> curr >> target;

    string temp = curr;
    Change(temp, target, true);
    Change(temp, target, false);

    if(ans == INT_MAX){
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}