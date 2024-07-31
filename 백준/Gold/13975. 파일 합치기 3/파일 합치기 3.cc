#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int t;
    cin >> t;

    for(int testCase = 0 ; testCase < t ; testCase++){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int k;
        cin >> k;

        for(int i = 0 ; i < k ; i++){
            int input;
            cin >> input;
            pq.push(input);
        }

        ll answer = 0;
        while(!pq.empty()){
            ll temp = 0;

            temp += pq.top();
            pq.pop();
            temp += pq.top();
            pq.pop();

            if(pq.size() > 0){
                pq.push(temp);
            }
            answer += temp;
        }
        cout << answer << '\n';
    }

    return 0;
}