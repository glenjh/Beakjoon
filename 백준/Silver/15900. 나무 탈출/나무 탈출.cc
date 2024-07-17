#include <iostream>
#include <vector>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string answer;
int n, cnt, chance;
vector<int> v[500001];
bool visited[500001];

void DFS(int x, int cnt){
    visited[x] = true;

    if(x != 1 && v[x].size() == 1){
        chance += cnt;
    }

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            DFS(next, cnt + 1);
            visited[next] = true;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1, 0);

    if(chance % 2 == 1){
        answer = "Yes";
    }else{
        answer = "No";
    }
    
    cout << answer << '\n';

    return 0;
}