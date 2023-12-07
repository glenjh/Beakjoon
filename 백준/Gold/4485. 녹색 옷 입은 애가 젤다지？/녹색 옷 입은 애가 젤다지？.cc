#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define MAX 126

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
int dist[MAX][MAX];
int arr[MAX][MAX];
int n;

void Dijkstra(int cost){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = cost;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n){ continue; }
            int nCost = cost + arr[nx][ny];
            if(dist[nx][ny] > nCost){
                dist[nx][ny] = nCost;
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
    }
}

int cnt = 1;

int main() {
    FastIO();

    while(true){
        for(int i = 0 ; i < MAX ; i++){
            for(int j = 0 ; j < MAX ; j++){
                dist[i][j] = INT_MAX;
            }
        }

        cin >> n;

        if(n == 0){ break; }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> arr[i][j];
            }
        }

        Dijkstra(arr[0][0]);
        cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] + dist[0][0] << '\n';
    }

    return 0;
}