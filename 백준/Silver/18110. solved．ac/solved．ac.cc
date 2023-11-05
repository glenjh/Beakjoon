#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n;
    double sum = 0;
    vector<int> v;
    cin >> n;
    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int sub = round(n * 0.15);
    
    int start = sub;
    int end = n - sub;

    for(int i = start ; i < end ; i++){
        sum += v[i];
    }

    double rel = sum / (n - 2*sub);
    cout << round(rel) << '\n';

    return 0;
}