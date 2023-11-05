#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b, n, m, answer = 0;
vector<int> v[1001];

bool visited[1001];
bool flag = false;

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        if(curr_x == b){
            flag = true;
            if(answer == 0){
                answer = curr_cnt;
            }
            else{
                answer = min(answer, curr_cnt);
            }
        }

        for(int i = 0 ; i < v[curr_x].size() ; i++){
            int next_x = v[curr_x][i];
            if(!visited[next_x]){
                q.push({next_x, curr_cnt+1});
                visited[next_x] = true;
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
    cin >> a >> b;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int before, after;
        cin >> before >> after;
        v[before].push_back(after);
        v[after].push_back(before);
    }

    BFS(a, 0);

    if(!flag){
        cout << -1 << '\n';
    }
    else{
        cout << answer << '\n';
    }

    return 0;
}