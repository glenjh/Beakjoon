#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, answer = 0;
    vector<int> v;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    for(int i = 0 ; i < n-1 ; i++){
        answer += v[i];
    }

    cout << answer << '\n';
    return 0;
}