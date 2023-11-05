#include <iostream>
#include <queue>

using namespace std;

int a, k;

bool visited[1000001];
int cnt[1000001] = {0, };

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == k){
            return;
        }

        if(0 < curr + 1 && curr + 1 <= 1000000 && !visited[curr + 1]){
            visited[curr + 1] = true;
            q.push(curr + 1);
            cnt[curr + 1] = cnt[curr] + 1;
        }

        if(0 < curr * 2 && curr * 2 <= 1000000 && !visited[curr * 2]){
            visited[curr * 2] = true;
            q.push(curr * 2);
            cnt[curr * 2] = cnt[curr] + 1;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> k;
    
    BFS(a);
    cout << cnt[k] << '\n';

    return 0;
}