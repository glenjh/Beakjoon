#include <iostream>
#include <queue>
#include <vector>
#define MAX 200001
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[MAX];

int main() {
    FastIO();

    vector<int> answers;

    while(true){

        vector<pair<int, int>> v[MAX];
        ll answer = 0, total = 0;
        int m, n;
        cin >> m >> n;

        if(m == 0 && n == 0){ break; }

        for(int i = 0 ; i <= m ; i++){
            visited[i] = false;
        }

        for(int i = 0 ; i < n ; i++){
            int a, b, cost;
            cin >> a >> b >> cost;
            total += cost;
            v[a].push_back({b, cost});
            v[b].push_back({a, cost});
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, 1});

        while(!pq.empty()){
            int cost = -pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if(!visited[curr]){
                visited[curr] = true;
                answer += cost;

                for(int i = 0 ; i < v[curr].size() ; i++){
                    int next = v[curr][i].first;
                    int nCost = v[curr][i].second;
                    if(!visited[next]){
                        pq.push({-nCost, next});
                    }
                }
            }
        }

        answers.push_back(total - answer);
    }

    for(auto it : answers){
        cout << it << '\n';
    }

    return 0;
}