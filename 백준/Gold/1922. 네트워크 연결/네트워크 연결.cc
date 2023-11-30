#include <iostream>
#include <vector>
#include <climits>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int cost[MAX][MAX];
    int dist[MAX];
    bool selected[MAX];
    int n, m, answer = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        dist[i] = INT_MAX;
        selected[i] = false;
        for(int j = 1 ; j <= n ; j++){
            cost[i][j] = INT_MAX;
        }
    }

    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    selected[1] = true;
    dist[1] = 0;
    for(int i = 1 ; i <= n ; i++){
        dist[i] = cost[1][i];
    }

    for(int i = 1 ; i <= n - 1 ; i++){
        int min = INT_MAX, idx;
        for(int j = 1 ; j <= n ; j++){
            if(selected[j]){ continue; }
            if(min > dist[j]){
                min = dist[j];
                idx = j;
            }
        }
        selected[idx] = true;
        answer += min;

        for(int j = 1 ; j <= n ; j++){
            if(selected[j]){ continue; }
            if(dist[j] > cost[idx][j]){
                dist[j] = cost[idx][j];
            }
        }
    }

    cout << answer << '\n';

    return 0;
}