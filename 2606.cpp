#include <iostream>
using namespace std;

int p[101];

int find(int a){
    if(p[a] == a){ return a; }
    else{ 
        p[a] = find(p[a]);
        return p[a]; 
    }
}

void union_com(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        p[pb] = pa;
    }
}

int main(){
    for(int i=0 ; i<101 ; i++){
        p[i] = i;
    }

    int n , m, com_p , com_c;
    int virused = 0;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> com_p >> com_c;
        union_com(com_p , com_c);
    }

    for(int i=2 ; i<101 ; i++){
        if(find(i) == find(1)){ virused++; }
    }

    cout << virused;
    return 0;
}