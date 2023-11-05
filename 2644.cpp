#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit_cnt[101] = {0, };
vector<int> v[101];
int n, first_man, second_man, m;

bool visited[101];

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
                q.push(child);
                visited[child] = true;
                visit_cnt[child] = visit_cnt[parent] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> first_man >> second_man;
    cin >> m;

    for(int i = 0 ; i< m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    BFS(first_man);

    if(visit_cnt[second_man] == 0){ cout << -1; }
    else{ cout << visit_cnt[second_man]; }

    return 0;
}