#include <iostream>
#include <vector>

using namespace std;

int t, n, m, cnt = 0;
vector<int> v[1001];
bool visited[1001];

void clear(){
    for(int i = 0 ; i < 1001 ; i++){
        visited[i] = false;
        while(!v[i].empty()){
            v[i].pop_back();
        }
    }
    cnt = 0;
}

void DFS(int x){
    visited[x] = true;
    cnt++;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next_country = v[x][i];
        if(!visited[next_country]){
            DFS(next_country);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        cin >> n >> m;
        for(int i = 0 ; i < m ; i++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        DFS(1);
        cout << cnt-1 << '\n';
        clear();
    }
    return 0;
}