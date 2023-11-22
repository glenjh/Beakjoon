#include <iostream>
#include <climits>
#define MAX 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX];
int nodeCnt[MAX];
int temp[MAX];

int My_Find(int a){
    if(a == p[a]){ return a; }
    return p[a] = My_Find(p[a]);
}

void My_Uni(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);
    if(pa == pb){ return; }

    if(nodeCnt[pa] > nodeCnt[pb]){
        p[pb] = pa;
        nodeCnt[pa] += nodeCnt[pb];
    }
    else{
        p[pa] = pb;
        nodeCnt[pb] += nodeCnt[pa];
    }

    p[pa] = pb;
}

int main() {
    FastIO();

    int cost[MAX];
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        temp[i] = INT_MAX;
        p[i] = i;
        cin >> cost[i];
    }
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        My_Uni(a, b);
    }

    for(int i = 1 ; i <= n ; i++){
        int root = My_Find(i);
        temp[root] = min(temp[root], cost[i]);
    }

    int answer = 0;
    for(int i = 1 ; i <= n ; i++){
        if(temp[i] != INT_MAX){
            answer += temp[i];
        }
    }

    if(answer > k){
        cout << "Oh no" << '\n';
    }
    else{
        cout << answer << '\n';
    }

    return 0;
}