#include <iostream>
#include <queue>

using namespace std;

int n, k;

queue<int> q;
bool visited[200001];
int cnt[200001] = {0,};

void BFS(int x){
    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int curr_pos = q.front();
        q.pop();

        if(curr_pos == k){
            return;
        }

        if(0 <= curr_pos * 2 && curr_pos * 2 <= 100000 && !visited[curr_pos*2]){
            q.push(curr_pos * 2);
            cnt[curr_pos * 2] += cnt[curr_pos];
            visited[curr_pos * 2] = true;
        }
        if(0 <= curr_pos - 1 && curr_pos - 1 <= 100000 && !visited[curr_pos-1]){
            q.push(curr_pos - 1);
            cnt[curr_pos - 1] = cnt[curr_pos] + 1;
            visited[curr_pos - 1] = true;
        }
        if(0 <= curr_pos + 1 && curr_pos + 1 <= 100000 && !visited[curr_pos+1]){
            q.push(curr_pos + 1);
            cnt[curr_pos + 1] = cnt[curr_pos] + 1;
            visited[curr_pos + 1] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    BFS(n);
    cout << cnt[k];
    return 0;
}