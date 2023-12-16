#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX], sz[MAX];

int My_Find(int a){
    if(p[a] == a){ return a; }
    return p[a] = My_Find(p[a]);
}

void My_Uni(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);

    if(pa == pb){ return; }

    if(sz[pa] > sz[pb]){
        p[pb] = pa;
        sz[pa] += sz[pb];
    }else{
        p[pa] = pb;
        sz[pb] += sz[pa];
    }
}

int main() {
    FastIO();

    vector<  pair<int, pair<int, int>> > v;
    int n, m;
    long long total = 0, sum = 0, group = 1;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
        sz[i] = 1;
    }

    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
        total += c;
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size() ; i++){
        int pa = My_Find(v[i].second.first);
        int pb = My_Find(v[i].second.second);
        if(pa != pb){
            My_Uni(v[i].second.first, v[i].second.second);
            sum += v[i].first;
            group += 1;
        }
    }

    if(group != n){
        cout << -1 << '\n';
    }else{
        cout << total - sum << '\n';
    }

    return 0;
}