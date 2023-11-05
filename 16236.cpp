#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<int> v[2001];

bool visited[2001];
bool flag = false;

void reset(){
    for(int i = 0 ; i < 2001 ; i++){
        visited[i] = false;
    }
}

void DFS(int x, int callCnt){
    if(callCnt == 4){
        flag = true;
        return;
    }
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(!visited[child]){
            visited[child] = true;
            DFS(child, callCnt+1);
            visited[child] = false;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0 ; i < n ; i++){
        DFS(i, 0);
        if(flag){ break; }
        reset();
    }

    if(flag){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}