#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, k, answer;
vector<int> apple;
vector<int> v[100001];
bool visited[100001];

void DFS(int x, int len){
    if(visited[x]){ return; }

    visited[x] = true;
    if(apple[x] == 1 && len <= k){
        answer += 1;
    }

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            DFS(next, len + 1);
        }
    }
}

int main() {
    FastIO();

    cin >> n >> k;
    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        apple.push_back(input);
    }

    DFS(0, 0);

    cout << answer << '\n';

    return 0;
}