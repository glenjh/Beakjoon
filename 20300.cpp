#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int n;
    long long M = 0;
    vector<long long> v;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        long long input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    
    
    if(n % 2 == 0){
        for(int i = 0 ; i < n/2 ; i++){
            long long sum = v[i] + v[n-1-i];
            if(sum > M){
                M = sum;
            }
        }
    }
    else{
        M = v[n - 1];

        for(int i = 0 ; i < n/2 ; i++){
            long long sum = v[i] + v[n-2-i];
            if(sum > M){
                M = sum;
            }
        }
    }
    cout << M << '\n';
    return 0;
}