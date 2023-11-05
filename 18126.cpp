#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
long long answer = 0;
vector<pair<int, long long>> v[5001];

bool visited[5001];

void reset(){
    for(int i = 0 ; i < 5001 ; i++){
        visited[i] = false;
    }
}

void BFS(int currRoom, int target, long long cnt){
    queue<pair<int, long long>> q;
    q.push({currRoom, cnt});
    visited[currRoom] = true;

    while(!q.empty()){
        int nextRoom = q.front().first;
        long long currCnt = q.front().second;
        q.pop();

        if(nextRoom == target){
            if(currCnt > answer){
                answer = currCnt;
            }
        }

        for(int i = 0 ; i < v[nextRoom].size() ; i++){
            int child = v[nextRoom][i].first;
            if(!visited[child]){
                long long nextCnt = currCnt + v[nextRoom][i].second;
                q.push({child, nextCnt});
                visited[child] = true;
            }
        }
    }
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n-1 ; i++){
        int a, b;
        long long t;
        cin >> a >> b >> t;
        v[a].push_back({b, t});
        v[b].push_back({a, t});
    }

    for(int i = 1 ; i <= n ; i++){
        BFS(1, i, 0);
        reset();
    }

    cout << answer << '\n';

    return 0;
}