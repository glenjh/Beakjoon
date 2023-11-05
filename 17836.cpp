#include <iostream>
#include <queue>

using namespace std;

int n, m, t, answer = 987654321;
int arr[101][101];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool visited[101][101];
bool visitedWithGram[101][101];

void BFS(int x, int y, bool hasGram, int cnt){
    queue< pair<pair<int, int>, pair<bool, int>>> q;
    q.push({{x, y}, {hasGram, cnt}});
    visited[x][y] = true;

    while(!q.empty()){
        int curr_x = q.front().first.first;
        int curr_y = q.front().first.second;
        bool havingGram = q.front().second.first;
        int currCnt = q.front().second.second;
        q.pop();

        if(arr[curr_x][curr_y] == 2){
            havingGram = true;
        }
    
        if(curr_x == n-1 && curr_y == m-1){
            answer = currCnt;
            return;
        }

        

        for(int i = 0 ; i < 4 ; i++){
            int next_x = curr_x + dir_x[i];
            int next_y = curr_y + dir_y[i];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m){ continue; }
            if(havingGram){
                if(!visitedWithGram[next_x][next_y]){
                    visitedWithGram[next_x][next_y] = true;
                    q.push({{next_x, next_y}, {havingGram, currCnt+1}});
                }
            }
            else{
                if(!visited[next_x][next_y] && arr[next_x][next_y] != 1){
                    visited[next_x][next_y] = true;
                    q.push({{next_x, next_y}, {havingGram, currCnt + 1}});
                }
            }
        }
    }
}


void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    cin >> n >> m >> t;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    BFS(0, 0, false, 0);

    if(answer <= 0 || answer > t){
        cout << "Fail" << '\n';
    }else{
        cout << answer << '\n';
    }

    return 0;
}