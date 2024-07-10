#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int broken[100001];

int main() {
    FastIO();

    int n, k, b, answer = 0;
    cin >> n >> k >> b;
    for(int i = 0 ; i < b ; i++){
        int input;
        cin >> input;
        broken[input] = 1;
    }

    int cnt = 0;
    for(int i = 1 ; i <= k ; i++){
        cnt += broken[i];
    }

    int l = 1, r = k + 1, temp = cnt;
    while(r <= n){
        temp -= broken[l];
        temp += broken[r];

        cnt = min(cnt, temp);

        l += 1;
        r += 1;
    }

    cout << cnt << '\n';

    return 0;
}