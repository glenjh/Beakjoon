#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[1000001];

int main() {
    FastIO();

    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        if(arr[i] == 1){
            v.push_back(i);
        }
    }

    if(v.size() < k){
        cout << -1 << '\n';
        return 0;
    }

    int l = 0, r = 0, answer = INT_MAX, cnt = 0, len = 0;

    for(int i = 0 ; i <= v.size() - k ; i++){
        answer = min(answer, v[i + k - 1] - v[i] + 1);
    }
    
    if(answer == INT_MAX){
        cout << - 1 << '\n';
    }
    else{
        cout << answer << '\n';
    }

    return 0;
}