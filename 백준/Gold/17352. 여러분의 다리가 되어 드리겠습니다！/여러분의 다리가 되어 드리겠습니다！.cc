#include <iostream>
#define MAX 300001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX];
int cnt[MAX];

int FindParent(int a){
    if(p[a] == a){
        return a;
    }
    return p[a] = FindParent(p[a]);
}

void Union(int a, int b){
    int pa = FindParent(a);
    int pb = FindParent(b);
    if(pa == pb) { return ;}

    if(cnt[pa] > cnt[pb]){
        p[pb] = pa;
        cnt[pa] += cnt[pb];
    }
    else{
        p[pa] = pb;
        cnt[pb] += cnt[pa]; 
    }
}

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
        cnt[i] = 0;
    }

    for(int i = 0 ; i < n - 2 ; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    
    int first = FindParent(1);
    for(int i = 2 ; i <= n ; i++){
        if(FindParent(i) != first){
            cout << first << ' ' << FindParent(i) << '\n';
            break;
        }
    }

    return 0;
}