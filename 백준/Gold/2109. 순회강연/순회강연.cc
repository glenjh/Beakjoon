#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[10001];

int main() {
    FastIO();

    priority_queue<pair<int, int>> pq;
    int n, answer = 0;  
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int d, p;
        cin >> p >> d;
        pq.push({p, d});
    }

    while(!pq.empty()){
        int day = pq.top().second;
        int cost = pq.top().first;

        for(int i = day ; i >= 1 ; i--){
            if(!visited[i]){
                visited[i] = true;
                answer += cost;
                break;
            }
        }

        pq.pop();
    }

    cout << answer << '\n';

    return 0;
}