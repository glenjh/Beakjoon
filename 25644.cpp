#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    vector<long long> v;
    long long n, m, mIdx, M = -1, answer = 0;
    cin >> n;

    for(long long i = 0 ; i < n ; i++){
        long long input;
        cin >> input;

        if(i == 0){
            m = input;
            continue;
        }

        if(input < m){
            m = input;
        }
        else if(input > m){
            M = input;
            answer = max(answer, M - m);
        }
    }
    
    cout << answer << '\n';

    return 0;
}