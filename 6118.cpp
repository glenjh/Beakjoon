#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, M = 0;
vector<int> v[20001];
vector<int> rel;
int cnt[20001] = {0, };

bool visited[20001];

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int i = 0 ; i < v[parent].size() ; i++){
            int child = v[parent][i];
            if(!visited[child]){
                visited[child] = true;
                cnt[child] = cnt[parent] + 1;
                q.push(child);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        BFS(i);
    }

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] > M){
            M = cnt[i];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] == M){
            rel.push_back(i);
        }
    }
    cout << rel[0] << ' ' << M << ' ' << rel.size() << '\n';
    return 0;
}