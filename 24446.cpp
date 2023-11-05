#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r, answer;
vector<int> v[100001];
int cnt[100001] = {0, };

bool visited[100001];

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front();
        q.pop();

        for(int i = 0 ; i < v[curr_x].size() ; i++){
            int child = v[curr_x][i];
            if(!visited[child]){
                q.push(child);
                cnt[child] = cnt[curr_x] + 1;
                visited[child] = true;
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

    cin >> n >> m >> r;
    for(int i = 0 ; i < m ; i++){
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    BFS(r);

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] == 0 && i != r){
            cout << -1 << '\n';
        }else{
            cout << cnt[i] << '\n';
        }
    }

    return 0;
}