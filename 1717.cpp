#include <iostream>
using namespace std;

int p[1000001];

int find(int a){
    if(a == p[a]){ return a; }
    else{ 
        return p[a] = find(p[a]);
    }
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        p[pb] = pa;
    }else { return; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0 ; i<1000001 ; i++){
        p[i] = i;
    }
    int flag;
    int a, b , n , m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> flag >> a >> b;
        if(flag == 0){
            uni(a,b);
        }else if(flag == 1){
            if(find(a) == find(b)){  cout << "YES" << '\n';}
            else{ cout << "NO" << '\n'; }
        }
    }
    return 0;
}