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

int p[100001];

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.second < b.second.second;
}

int My_Find(int a){
    if(p[a] == a){ return a; }
    return p[a] = My_Find(p[a]);
}

void My_Union(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);

    if(pa == pb){ return; }
    if(pa > pb){
        p[pa] = pb;
    }
    else{
        p[pb] = pa;
    }
}


int main() {
    FastIO();

    int v, e;
    ll answer = 0;
    vector<pair<int, pair<int, int>>> nodes;
    cin >> v >> e;
    for(int i = 1 ; i <= v ; i++){
        p[i] = i;
    }

    for(int i = 0 ; i < e ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        nodes.push_back({a, {b, c}});
    }

    sort(nodes.begin(), nodes.end(), comp);

    for(int i = 0 ; i < nodes.size() ; i++){
        int pa = My_Find(nodes[i].first), pb = My_Find(nodes[i].second.first);

        if(pa != pb){
            My_Union(nodes[i].first, nodes[i].second.first);
            answer += nodes[i].second.second;
        }
    }

    cout << answer << '\n';

    return 0;
}