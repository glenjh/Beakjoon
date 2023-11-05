#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, cnt = 1;

vector<int> v[100001];
int visit_cnt[100001] = {0, };
bool visited[100001];

queue<int> q;

void BFS(int x){
    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int curr_x = q.front();
        // cout << curr_x << ' ';
        visit_cnt[curr_x] += cnt++;
        q.pop();

        for(int i = 0 ; i < v[curr_x].size() ; i++){
            int child = v[curr_x][i];
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin() , v[i].end());
    }

    BFS(r);

    for(int i = 1 ; i <= n ; i++){
        cout << visit_cnt[i] << '\n';
    }
    return 0;
}