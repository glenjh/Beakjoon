#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(int a, int b){
    return a > b;
}

int main(){
    FastIO();

    vector <int> v;
    int n, sum = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0 ; i < n-1 ; i++){
        sum += v[i] + v[i+1];
        v[i+1] = v[i];
    }

    cout << sum << '\n';

    return 0;
}