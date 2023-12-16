#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX];
int sz[MAX];

void Reset(){
    for(int i = 0 ; i < MAX ; i++){
        p[i] = i;
        sz[i] = 1;
    }
}

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

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first > b.first;
}

    int main()
{
    FastIO();

    int n, m, worst = 0, best = 0;
    vector< pair<int, pair<int, int>> > v;
    cin >> n >> m;

    for(int i = 0 ; i <= m ; i++){
        int a, b, c;
        cin >> a >> b >> c; // 오르막길이 0, 내리막은 1
        v.push_back({c, {a, b}});
    }

    Reset();
    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size() ; i++){
        int pa = My_Find(v[i].second.first);
        int pb = My_Find(v[i].second.second);
        if(pa != pb){
            My_Uni(v[i].second.first, v[i].second.second);
            if(v[i].first == 0){
                worst++;
            }
        }
    }

    Reset();
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++){
        int pa = My_Find(v[i].second.first);
        int pb = My_Find(v[i].second.second);
        if (pa != pb){
            My_Uni(v[i].second.first, v[i].second.second);
            if(v[i].first == 0){
                best++;
            }
        }
    }

    cout << worst * worst - best * best << '\n';


    return 0;
}