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

    vector<int> v;
    long long n, answer = 0, sum = 0;
    cin >> n;
    for(int i = n ; i >= 1 ; i--){
        int input;
        cin >> input;
        sum += input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i++){
        sum = sum - v[i];
        answer += sum * v[i];
    }

    cout << answer << '\n';

    return 0;
}