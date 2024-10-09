#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int times[10001];
int ans[10001]; // ans[a] = b -> a 전에 b를 거쳐서 간다
vector<pair<int, int>> v[10001];

void Reset(){
    for(int i = 1 ; i <= n ; i++){
        times[i] = INF;
    }
}

void Djikstar(int start){
    Reset();
    times[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int curr = pq.top().second;
        int currTime = pq.top().first;
        pq.pop();

        if(times[curr] < currTime){ continue; }

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i].first;
            int nextTime = v[curr][i].second;

            if(times[next] > times[curr] + nextTime){
                ans[next] = curr;
                times[next] = times[curr] + nextTime;
                pq.push({times[next], next});
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(i == start){
            cout << "-" << ' ';
        }
        else if(ans[i] == start){
            cout << i << ' ';
        }
        else{
            int now = i;
            while(true){
                if(ans[now] == start){
                    cout << now << ' ';
                    break;
                }
                else {
                    now = ans[now];
                }
            }
        }
    }
    cout << '\n';
}


int main() {
    FastIO();

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back({b, t});
        v[b].push_back({a, t});
    }
    
    for(int i = 1 ; i <= n ; i++){
        Djikstar(i);
    }

    return 0;
}