#include <iostream>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int a, b, n, m, answer;
int add[6] = {1, -1, a, -a, b, -b};
int mul[2] = {a, b}; 

bool visited[100001];

void BFS(int curr, int cnt){ // +1, -1, +-a, +-b, *a, *b
    queue<pair<int, int>> q;
    visited[curr] = true;
    q.push({curr, cnt});

    while(!q.empty()){
        int nCurr = q.front().first;
        int nCnt = q.front().second;
        q.pop();

        if(nCurr == m){
            answer = nCnt;
            return;
        }

        for(int i = 0 ; i < 6 ; i++){
            int next = nCurr + add[i];
            if(0 <= next && next <= 100000){
                if(!visited[next]){
                    visited[next] = true;
                    q.push({next, nCnt + 1});
                }
            }   
        }

        for(int i = 0 ; i < 2 ; i++){
            int next = nCurr * mul[i];
            if (0 <= next && next <= 100000){
                if (!visited[next]){
                    visited[next] = true;
                    q.push({next, nCnt + 1});
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> a >> b >> n >> m;
    add[2] = a, add[3] = -a, add[4] = b, add[5] = -b;
    mul[0] = a, mul[1] = b;
    BFS(n, 0);
    cout << answer << '\n';

    return 0;
}