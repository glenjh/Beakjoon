#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer;
vector<pair<int, int>> ladder, snake;
int dir[6] = {1, 2, 3, 4, 5, 6};

bool visited[101];

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while (!q.empty()){
        int curr = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        for(auto it : ladder){
            if(it.first == curr){
                curr = it.second;
            }
        }

        for(auto it : snake){
            if(it.first == curr){
                curr = it.second;
            }
        }

        if(curr == 100){
            if(answer == 0){
                answer = curr_cnt;
            }else{
                answer = min(answer, curr_cnt);
            }
        }

        for(int i = 0 ; i < 6 ; i++){
            int next = curr + dir[i];
            if(next > 100){ continue; }
            if(!visited[next]){
                q.push({next, curr_cnt + 1});
                visited[next] = true;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        ladder.push_back({start, end});
    }

    for(int i = 0 ; i < m ; i++){
        int start, end;
        cin >> start >> end;
        snake.push_back({start, end});
    }

    BFS(1, 0);

    cout << answer << '\n';

    return 0;
}