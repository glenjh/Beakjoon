#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[300001];
int cnt[300001] = {0,};

bool visited[300001];
bool flag = false;

int n, m, k, x;

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i];
            if(!visited[next]){
                visited[next] = true;
                cnt[next] = cnt[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> x;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);

    }

    BFS(x);

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] == k){
            flag = true;
            cout << i << '\n';
        }
    }

    if(!flag){
        cout << -1 << '\n';
    }

    return 0;
}