#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define MAX 501
#define INF INT_MAX

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int arr[501][501]; // 0 -> 안전, 1 -> 위험, 2 -> 죽음
int lost[501][501];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

void Djikstar(int x, int y){
    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {x, y}});

    while(!pq.empty()){
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int currLost = pq.top().first;
        pq.pop();

        if(lost[cx][cy] < currLost){ continue; }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx > 500 || ny > 500){ continue; }
            if(arr[nx][ny] == 2){ continue; }

            if(arr[nx][ny] == 1){
                int nextLost = currLost + 1;
                if (lost[nx][ny] > nextLost){
                    lost[nx][ny] = nextLost;
                    pq.push({lost[nx][ny], {nx, ny}});
                }
            }
            else{
                if (lost[nx][ny] > currLost){
                    lost[nx][ny] = currLost;
                    pq.push({lost[nx][ny], {nx, ny}});
                }
            }
        }
    }
}

int main() {
    FastIO();

    for(int i = 0 ; i < 501 ; i++){
        for(int j = 0 ; j < 501 ; j++){
            lost[i][j] = INF;
        }
    }

    // 위험한 구역 생성
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 > x2){
            swap(x1, x2);
        }
        if(y1 > y2){
            swap(y1, y2);
        }

        for(int j = x1 ; j <= x2 ; j++){
            for(int k = y1 ; k <= y2 ; k++){
                arr[j][k] = 1;
            }
        }
    }

    // 죽음의 구역 생성
    cin >> m;
    for (int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2){
            swap(x1, x2);
        }
        if (y1 > y2){
            swap(y1, y2);
        }

        for (int j = x1; j <= x2; j++){
            for (int k = y1; k <= y2; k++){
                arr[j][k] = 2;
            }
        }
    }
    
    lost[0][0] = 0;
    Djikstar(0, 0);

    if(lost[500][500] == INF){
        cout << -1 << '\n';
    }
    else{
        cout << lost[500][500] << '\n';
    }

    return 0;
}