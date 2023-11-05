#include <iostream>
#include <vector>

using namespace std;

int n, m, x, answer = 0;
vector<int> v[100001];

bool visited[100001];

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            answer++;
            DFS(next);
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

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    cin >> x;

    DFS(x);
    cout << answer << '\n';

    return 0;
}