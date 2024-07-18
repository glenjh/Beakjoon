#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    long long n, answer = 0;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0 ; i < n ; i++){
        answer += abs(v[i] - (i + 1));
    }

    cout << answer << '\n';

    return 0;
}