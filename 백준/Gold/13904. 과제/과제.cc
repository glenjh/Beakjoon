#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[1001];

int main() {
    FastIO();

    priority_queue<pair<int, int>> pq;
    int n, answer = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int d, w;
        cin >> d >> w;
        pq.push({w, d});
    }

    while(!pq.empty()){
        int dayLeft = pq.top().second;
        int grade = pq.top().first;
        pq.pop();

        for(int i = dayLeft ; i >= 1 ; i--){
            if(!visited[i]){
                visited[i] = true;
                answer += grade;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}