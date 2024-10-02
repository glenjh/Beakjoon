#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll n, m, r, cnt = 1;
ll ans;
vector<ll> v[100001];
ll d[100001];
ll num[100001];

bool visited[100001];


void DFS(int x, int dep){
    if(visited[x]){ return; }
    visited[x] = true;

    d[x] = dep;
    num[x] = cnt;
    cnt += 1;

    for(int i = 0 ; i < v[x].size() ; i++){
        int nx = v[x][i];
        if(!visited[nx]){
            DFS(nx, dep + 1);
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m >> r;
    for(int i = 1 ; i <= n ; i++){
        d[i] = -1;
    }
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin(), v[i].end());
    }

    DFS(r, 0);

    for(int i = 1 ; i <= n ; i++){
        ans += d[i] * num[i];
    }
    cout << ans << '\n';

    return 0;
}