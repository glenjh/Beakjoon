#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< pair<int, pair<int, int>> > vec;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[1001];
int n, m;

string s[1001];

int My_Find(int a){
    if(p[a] == a){ return a; }
    else{
        return p[a] = My_Find(p[a]);
    }
}

void My_Uni(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);

    if(pa != pb){
        p[pa] = pb;
    }
}

int main() {
    FastIO();

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> s[i];
    }

    for(int i = 0 ; i < m ; i++){
        int u, v, d;
        cin >> u >> v >> d;
        vec.push_back({d, {u, v}});
        vec.push_back({d, {v, u}});
    }

    sort(vec.begin(), vec.end());

    int dist = 0, cnt = 0;
    for(int i = 0 ; i < vec.size() ; i++){
        int a = vec[i].second.first;
        int b = vec[i].second.second;

        int pa = My_Find(a);
        int pb = My_Find(b);

        if(s[a] != s[b] && pa != pb){
            My_Uni(pa, pb);
            dist += vec[i].first;
            cnt += 1;
        }
    }

    if(cnt == n - 1){
        cout << dist << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}