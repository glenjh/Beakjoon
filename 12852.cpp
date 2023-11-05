#include <iostream>
#include <queue>

using namespace std;

int n, answer = 0;

bool visited[1000001];
int temp[1000001] = {0, };

void print(int x){
    if(x == 0){ return; }
    print(temp[x]);
    cout << x << ' ';
}

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        if(curr_x == 1){
            cout << curr_cnt << '\n';
            print(1);
            return;
        }

        if(curr_x % 3 == 0){
            int next_x = curr_x / 3;
            if(!visited[next_x]){
                visited[next_x] = true;
                temp[next_x] = curr_x;
                q.push({next_x, curr_cnt+1});
            }
        }

        if(curr_x % 2 == 0){
            int next_x = curr_x / 2;
            if(!visited[next_x]){
                visited[next_x] = true;
                temp[next_x] = curr_x;
                q.push({next_x, curr_cnt+1});
            }
        }

        if(curr_x >= 2){
            int next_x = curr_x - 1;
            if(!visited[next_x]){
                visited[next_x] = true;
                temp[next_x] = curr_x;
                q.push({next_x, curr_cnt+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    BFS(n, 0);

    return 0;
}