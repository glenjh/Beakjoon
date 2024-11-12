#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[200001];
map<int, int> m;

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int cnt = 0, ans = 0;

    m[arr[l]] += 1;
    while(r < n){
        r++;
        if(r == n){ break; }
        m[arr[r]]++;

        if (m.size() > 2){
            m[arr[l]]--;
            if (m[arr[l]] == 0){
                m.erase(arr[l]);
            }
            l++;
        }

        else if(m.size() == 2){
            int temp = 0;
            for(auto it : m){
                temp += it.second;
            }
            ans = max(ans, temp);
        }
    }

    if(ans == 0){
        for(auto it : m){
            ans += it.second;
        }
    }
    cout << ans << '\n';

    return 0;
}