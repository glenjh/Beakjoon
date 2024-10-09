#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define ll long long int
#define INF INT_MAX

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll times[10001];
int t, n, d, c;
ll totalCnt, totalTime;
vector<pair<int, int>> v[10001];

void Djikstra(int x){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while(!pq.empty()){
        int curr = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int nextPC = v[curr][i].first;
            int nextTime = v[curr][i].second;
    
            if(times[nextPC] > times[curr] + nextTime){
                times[nextPC] = times[curr] + nextTime;
                pq.push({times[nextPC], nextPC});
            }
        }
    }
}

int main() {
    FastIO();

    cin >> t;
    for(int testCase = 0 ; testCase < t ; testCase++){
        totalCnt = 0, totalTime = 0;

        cin >> n >> d >> c;
        for(int i = 1 ; i <= n ; i++){
            times[i] = INF;
            v[i].clear();
        }

        for(int i = 0 ; i < d ; i++){
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a, s});
        }

        times[c] = 0;
        Djikstra(c);

        for(int i = 1 ; i <= n ; i++){
            if(times[i] != INF){
                totalCnt += 1;
                totalTime = max(totalTime, times[i]);
            }
        }

        cout << totalCnt << ' ' << totalTime << '\n';
    }

    return 0;
}