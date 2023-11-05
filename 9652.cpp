#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int n;
    cin >> n;
    
    int A_cnt[50] = {0, };
    int B_cnt[50] = {0, };

    A_cnt[0] = 1;
    B_cnt[1] = 1;

    for(int i = 2 ; i < n+2 ; i++){
        A_cnt[i] = A_cnt[i-1] + A_cnt[i-2];
        B_cnt[i] = B_cnt[i-1] + B_cnt[i-2]; 
    }

    cout << A_cnt[n] << ' ' << B_cnt[n] << '\n';

    return 0;
}