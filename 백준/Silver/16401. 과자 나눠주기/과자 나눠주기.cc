#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v;

int main() {
    FastIO();

    int m, n, ans = 0, M = 0;
    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        if(input > M){
            M = input;
        }
        v.push_back(input);
    }

    int l = 1, r = M;
    while(l <= r){
        int cnt = 0;
        int mid = (l + r) / 2;

        int curr = mid;

        for(int i = 0 ; i < n ; i++){
            int snack = v[i];
            while(true){
                snack -= curr;
                if(snack >= 0){
                    cnt += 1;
                }
                else{
                    break;
                }
            }
        }

        if(cnt >= m){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}