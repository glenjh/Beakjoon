#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<int> v, sortedVec;
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        sum += input;
        v.push_back(input);
    }

    int ans = sum;

    sortedVec = v;
    sort(sortedVec.begin(), sortedVec.end());

    int start = sortedVec[n - 1], end = sum;
    while(start <= end){
        int mid = (start + end) / 2;

        int money = mid, cnt = 1;
        for(int i = 0 ; i < n ; i++){
            if(money >= v[i]){
                money -= v[i];
            }
            else{
                cnt += 1;
                money = mid - v[i];
            }
        }

        if(cnt <= m){
            ans = mid;
            end = mid - 1;
        }
        else if(cnt > m){
            start = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}