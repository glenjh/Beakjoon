#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define INF INT_MAX

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int v, e, p;
int d[5001];
vector<pair<int, int>> vec[5001];

void Djikstra(int x){
    for (int i = 0; i < 5001; i++){
        d[i] = INF;
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        int cx = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        if(d[cx] < cCost){ continue; }

        for(int i = 0 ; i < vec[cx].size() ; i++){
            int nx = vec[cx][i].first;
            if(d[nx] > cCost + vec[cx][i].second){
                d[nx] = cCost + vec[cx][i].second;
                pq.push({d[nx], nx});
            }
        }
    }
}

int main() {
    FastIO();

    cin >> v >> e >> p;

    for(int i = 0 ; i < e ; i++){
        int here, there, cost;
        cin >> here >> there >> cost;
        vec[here].push_back({there, cost});
        vec[there].push_back({here, cost});
    }

    Djikstra(1);

    int startToP = d[p];
    int startToV = d[v];

    Djikstra(p);
    int pToV = d[v];

    if(startToP + pToV <= startToV){
        cout << "SAVE HIM" << '\n';
    }
    else{
        cout << "GOOD BYE" << '\n';
    }

    return 0;
}