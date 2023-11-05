#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, k, target;
int val[100001];
vector<int> tree[100001];

bool visited[100001];

void DFS(int x, int cnt){
    if(visited[x]){ return; }
    visited[x] = true;

    if(val[x] == k){
        cout << cnt << '\n';
        return;
    }

    for(int i = 0 ; i < tree[x].size() ; i++){
        int nextNode = tree[x][i];
        if(!visited[nextNode]){
            DFS(nextNode, cnt+1);
        }
    }
}

int main(){
    FastIO();

    cin >> n >> k;
    for(int i = 0 ; i < n-1 ; i++){
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
    }

    for(int i = 0 ; i < n ; i++){
        cin >> val[i];
    }

    DFS(0, 0);

    return 0;
}