#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#define INF INT_MAX

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, k;
int idx = 0;
int d[1001][101];

vector<pair<int, int>> v[101];
vector<int> friends;

void Dijikstra(int x){
    d[idx][x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while(!pq.empty()){
        int cx = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        if(d[idx][cx] < cCost){ continue; }

        for(int i = 0 ; i < v[cx].size() ; i++){
            int nx = v[cx][i].first;
            int nCost = v[cx][i].second;
            if(d[idx][nx] > d[idx][cx] + nCost){
                d[idx][nx] = d[idx][cx] + nCost;
                pq.push({d[idx][nx], nx});
            }
        }
    }
}

int main() {
    FastIO();

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        idx = 0;
        friends.clear();

        int ans = 0, totalDist = INT_MAX;
        cin >> n >> m;
        for (int i = 0; i < 101 ; i++){
            for (int j = 0; j < 101; j++){
                d[i][j] = INF;
            }
        }

        friends.clear();
        for(int i = 1 ; i <= n ; i++){
            v[i].clear();
        }

        for(int i = 0 ; i < m ; i++){
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }

        cin >> k;
        for(int i = 0 ; i < k ; i++){
            int input;
            cin >> input;
            friends.push_back(input);
        }

        for(auto it : friends){
            Dijikstra(it);
            idx += 1;
        }

        for(int i = 1 ; i <= n ; i++){
            int temp = 0;
            for(int j = 0 ; j < idx ; j++){
                temp += d[j][i];
            }
            if(totalDist > temp){
                totalDist = temp;
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}