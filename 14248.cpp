#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> v;
bool visited[100001];

void DFS(int curr){
    if(visited[curr]){ return; }
    visited[curr] = true;
    int how_many_move = v[curr - 1];
    cnt += 1;

    int moves[2] = {how_many_move, -how_many_move};
    for(int i = 0 ; i < 2 ; i++){
        int next = curr + moves[i];
        if(next > n || next < 1){ continue; }
        if(!visited[next]){
            DFS(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> s;

    DFS(s);
    cout << cnt << '\n';

    return 0;
}