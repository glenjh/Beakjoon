#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer;
vector<int> v[501];

bool visited[501];

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front().first, curr_cnt = q.front().second;
        q.pop();

        if(curr_cnt == 1 || curr_cnt == 2){
            answer++;
        }

        for(int i = 0 ; i < v[curr_x].size() ; i++){
            int next_x = v[curr_x][i];
            if(!visited[next_x]){
                visited[next_x] = true;
                q.push({next_x, curr_cnt + 1});
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    BFS(1, 0);

    cout << answer << '\n';

    return 0;
}