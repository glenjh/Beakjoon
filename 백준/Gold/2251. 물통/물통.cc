#include <iostream>
#include <set>
#include <vector>
#define MAX 201

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

set<int> s;
int buket[3]; // 0 1 2

bool visited[MAX][MAX][MAX];

void DFS(int a, int b, int c){
    if(visited[a][b][c]){ return; }
    visited[a][b][c] = true;

    if(a == 0){
        s.insert(c);
    }

    // a -> b
    if(a + b > buket[1]){
        DFS(a + b - buket[1], buket[1], c);
    }else{
        DFS(0, b + a, c);
    }

    // a -> c
    if(a + c > buket[2]){
        DFS(a + c - buket[2], buket[2], c);
    }else{
        DFS(0, b, c + a);
    }

    // b -> a
    if(b + a > buket[0]){
        DFS(buket[0], b + a - buket[0], c);
    }else{
        DFS(a + b, 0, c);
    }

    // b -> c
    if(b + c > buket[2]){
        DFS(a, b + c - buket[2], buket[2]);
    }else{
        DFS(a, 0, c + b);
    }

    // c -> a
    if(c + a > buket[0]){
        DFS(buket[0], b, c + a - buket[0]);
    }else{
        DFS(a + c, b, 0);
    }

    // c -> b
    if(c + b > buket[1]){
        DFS(a, buket[1], c + b - buket[1]);
    }else{
        DFS(a, b + c, 0);
    }
}

int main() {
    FastIO();

    for(int i = 0 ; i < 3 ; i++){
        cin >> buket[i];
    }

    DFS(0, 0, buket[2]);
    for(auto it : s){
        cout << it << ' ';
    }

    return 0;
}