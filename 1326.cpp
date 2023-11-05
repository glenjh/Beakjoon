#include <iostream>
#include <queue>

using namespace std;

int a, b, n, answer = -1;
int arr[10001];

bool visited[10001];

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        if(curr_x == b){
            answer = curr_cnt;
            return;
        }

        for(int nextPos = curr_x + arr[curr_x] ; nextPos <= n ; nextPos += arr[curr_x]){
            if(!visited[nextPos] && nextPos <= 10000){
                visited[nextPos] = true;
                q.push({nextPos, curr_cnt+1});
            }
        }

        for(int nextPos = curr_x - arr[curr_x] ; nextPos > 0 ; nextPos -= arr[curr_x]){
            if(!visited[nextPos] && nextPos > 0){
                visited[nextPos] = true;
                q.push({nextPos, curr_cnt+1});
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

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    cin >> a >> b;

    BFS(a, 0);

    cout << answer << '\n';
    
    return 0;
}