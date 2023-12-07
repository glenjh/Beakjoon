#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#define MAX 101

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
int n, m;
int dist[MAX][MAX];
int arr[MAX][MAX];
priority_queue< pair<int, pair<int, int>> > pq;

void Dijkstra(){
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
            int ncost = cost + arr[nx][ny];

            if(dist[nx][ny] > ncost){
                dist[nx][ny] = ncost;
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
    }
}

int main() {
    FastIO();

    for (int i = 0; i < MAX; i++){
        for(int j = 0 ; j < MAX ; j++){
            dist[i][j] = INT_MAX;
        }
    }

    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j] - '0';
        }
    }

    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    Dijkstra();

    cout << dist[n - 1][m - 1] << '\n';

    return 0;
}