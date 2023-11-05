#include <iostream>
#include <queue>

using namespace std;

int n, k;

queue<int> q;
bool visited[100001];
int cnt[100001] = {0, };

void DFS(int x){
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr_pos = q.front();
        q.pop();

        if(0 <= curr_pos-1 && curr_pos-1 <= 100000 && !visited[curr_pos-1]){
            q.push(curr_pos-1);
            cnt[curr_pos-1] = cnt[curr_pos] + 1;
            visited[curr_pos-1] = true;
        }
        if(0 <= curr_pos+1 && curr_pos+1 <= 100000 && !visited[curr_pos+1]){
            q.push(curr_pos+1);
            cnt[curr_pos+1] = cnt[curr_pos] + 1;
            visited[curr_pos+1] = true;
        }
        if(0 <= curr_pos * 2 && curr_pos * 2 <= 100000 && !visited[2*curr_pos]){
            q.push(curr_pos*2);
            cnt[curr_pos*2] = cnt[curr_pos] + 1;
            visited[2*curr_pos] = true;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    DFS(n);
    cout << cnt[k];
    return 0;
}