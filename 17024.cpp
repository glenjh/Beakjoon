#include <iostream>
#include <vector>

using namespace std;

int n, k, answer = -1;
vector<int> v[151];

bool visited[151];

void DFS(int x, int cnt){
    if(visited[x]){ return; }
    visited[x] = true;

    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(child == k){
            answer = cnt;
            return;
        }
        if(!visited[child]){
            DFS(child, cnt+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v[i].push_back(input);
    }

    DFS(0, 1);

    cout << answer << '\n';

    return 0;
}