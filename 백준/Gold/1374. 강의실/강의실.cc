#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> classes;
    priority_queue<ll, vector<ll>, greater<ll>> endTime;
    int n, answer = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        ll classNum, start, end;
        cin >> classNum >> start >> end;
        classes.push({start, end});
    }

    while(!classes.empty()){
        ll start = classes.top().first;
        ll end = classes.top().second;

        if(endTime.empty()){
            answer += 1;
            endTime.push(end);
            classes.pop();
        }
        else{
            if(start < endTime.top()){
                answer += 1;
                endTime.push(end);
                classes.pop();
            }
            else{
                endTime.pop();
                endTime.push(end);

                classes.pop();
            }
        }
    }

    cout << answer << '\n';

    return 0;
}