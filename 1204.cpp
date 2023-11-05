#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> v[1001];

bool visited[1001];

void reset(){
    for(int i = 0 ; i < 1001 ; i++){
        visited[i] = false;
    }
}

void BFS(int x, int target){
    queue<pair<int, int>> q;
    q.push({x, 0});
    visited[x] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int currDist = q.front().second;
        q.pop();

        if(curr == target){
            cout << currDist << '\n';
            return;
        }

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i].first;
            int nextDist = currDist + v[curr][i].second;
            if(!visited[next]){
                q.push({next, nextDist});
                visited[next] = true;
            }
        }
    }
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n-1 ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        BFS(a, b);
        reset();
    }

    return 0;
}