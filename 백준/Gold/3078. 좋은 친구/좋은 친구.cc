#include <iostream>
#include <string>
#include <queue>
#define ll long long

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

queue<int> q[21];

int main() {
    FastIO();

    int n, k;   
    ll answer = 0;

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        int len = input.length();

        while(!q[len].empty() && i - q[len].front() > k){
            q[len].pop();
        }

        answer += q[len].size();
        q[len].push(i);
    }

    cout << answer << '\n';

    return 0;
}