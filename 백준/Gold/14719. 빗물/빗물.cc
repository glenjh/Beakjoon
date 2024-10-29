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

    int h, w, ans = 0;
    cin >> h >> w;
    vector<int> v, right(w), left(w);

    for(int i = 0 ; i < w ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    left[0] = v[0];
    for(int i = 1 ; i < w ; i++){
        left[i] = max(v[i], left[i - 1]);
    }

    right[w - 1] = v[w - 1];
    for(int i = w - 2 ; i >= 0 ; i--){
        right[i] = max(v[i], right[i + 1]);
    }

    for(int i = 1 ; i < w - 1 ; i++){
        int H = min(left[i], right[i]);

        if(H > v[i]){
            ans += H - v[i];
        }
    }

    cout << ans << '\n';

    return 0;
}