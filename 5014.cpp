#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int cnt[1000001] = {0,};
queue<int> q;

bool visited[1000001] = {false, };
bool flag = false;

void BFS(int x){
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int curr_floor = q.front();
        q.pop();

        if(curr_floor == g){
            flag = true;
            return;
        }

        if(1 <= curr_floor - d && curr_floor - d <= f && !visited[curr_floor - d]){
            q.push(curr_floor - d);
            visited[curr_floor - d] = true;
            cnt[curr_floor - d] = cnt[curr_floor] + 1;
        }

        if(1 <= curr_floor + u && curr_floor + u <= f && !visited[curr_floor + u]){
            q.push(curr_floor + u);
            visited[curr_floor + u] = true;
            cnt[curr_floor + u] = cnt[curr_floor] + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> f >> s >> g >> u >> d;
    visited[s] = true;
    BFS(s);

    if(!flag){ cout << "use the stairs" << '\n'; }
    else{ cout << cnt[g] << '\n'; }

    return 0;
}