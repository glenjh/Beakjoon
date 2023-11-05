#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, answer;
vector<int> v[501];

bool visited[501];

void reset(){
    answer = 0;
    for (int i = 0; i < 501; i++){
        visited[i] = false;
        v[i].clear();
    }
}

bool DFS(int curr, int before){
    visited[curr] = true;

    for(int i = 0 ; i < v[curr].size() ; i++){
        int next = v[curr][i];
        if(next == before){ continue; }
        if(visited[next]){ return false; }
        if(!DFS(next, curr)){ return false; }
    }

    return true;
}

int main(){
    FastIO();

    int testCase = 1;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0){  break; }

        for(int i = 0 ; i < m ; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                if(DFS(i, 0)){
                    answer++;
                }
            }
        }

        cout << "Case " << testCase << ": ";
        testCase++;

        if(answer == 0){
            cout << "No trees." << '\n';
        }else if(answer == 1){
            cout << "There is one tree." << '\n';
        }else{
            cout << "A forest of " << answer << " trees." << '\n';
        }
        reset();
    }

    return 0;
}