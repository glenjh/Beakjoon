#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[MAX];

int main() {
    FastIO();

    vector<pair<int, int>> v[MAX];
    int n;
    long long answer = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int input;
            cin >> input;
            if(input != 0){
                v[i].push_back({j, input});
            }
        }
    }

    priority_queue< pair<int, int> > pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(!visited[x]){
            visited[x] = true;
            answer += cost;

            for(int i = 0 ; i < v[x].size() ; i++){
                int next = v[x][i].first;
                int nCost = v[x][i].second;
                if(!visited[next]){
                    pq.push({-nCost, next});
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}