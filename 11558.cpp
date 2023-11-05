#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10001];
int t, n, answer;

bool visited[10001];

void reset(){
    for(int i = 0 ; i < 10001 ; i++){
        visited[i] = false;
        v[i].clear();
        answer = 0;
    }
}

void DFS(int curr, int target, int cnt){
    if(visited[curr]){ return; }
    visited[curr] = true;

    for(int i = 0 ; i < v[curr].size() ; i++){
        int child = v[curr][i];
        if(child == target){
            answer = cnt;
            return;
        }
        if(!visited[child]){
            DFS(child, target, cnt+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        cin >> n;
        
        for(int i = 1 ; i <= n ; i++){
            int input;
            cin >> input;
            v[i].push_back(input);
        }

        DFS(1, n ,1);
        cout << answer << '\n';
        reset();
    }

    return 0;
}