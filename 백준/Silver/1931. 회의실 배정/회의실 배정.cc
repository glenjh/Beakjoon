#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    int n, answer = 1;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        pq.push({end, start});
    }

    int endTime = pq.top().first;
    pq.pop();

    while(!pq.empty()){
        if(pq.top().second >= endTime){
            answer += 1;
            endTime = pq.top().first;
        }
        pq.pop();
    }

    cout << answer << '\n';

    return 0;
}