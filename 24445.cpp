#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, cnt = 1;

int visit_cnt[100001] = {0, };
vector<int> v[100001];
queue<int> q;

bool visited[100001];

void BFS(int x){
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr_x = q.front();
        visit_cnt[curr_x] += cnt++;
        q.pop();

        for(int i = 0 ; i < v[curr_x].size() ; i++){
            int sibling = v[curr_x][i];
            if(!visited[sibling]){
                q.push(sibling);
                visited[sibling] = true;
            }
        }
    }
}

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    for(int i = 0 ; i <  m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin() , v[i].end(), comp);
    }

    BFS(r);

    for(int i = 1;  i <= n ; i++){
        cout << visit_cnt[i] << '\n';
    }

    return 0;
}