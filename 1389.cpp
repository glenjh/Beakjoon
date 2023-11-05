#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, minimum = 99999999, answer;
int cnt[101][101] = {0, };
vector<int> v[101];

bool visited[101];

void clear(){
    for(int i = 0 ; i < 101 ; i++){
        visited[i] = false;
    }
}

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int i = 0 ; i < v[parent].size() ; i++){
            int child = v[parent][i];
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                cnt[child][x] = cnt[parent][x] + 1;
            } 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    for(int i = 1 ; i <= n ; i++){
        BFS(i);
        clear();
    }

    for(int i = 1 ; i <= n ; i++){
        int sum = 0;
        for(int j = 1 ; j <= n ; j++){
            sum += cnt[i][j];
        }
        if(minimum > sum){
            minimum = sum;
            answer = i;
        }
    }

    cout << answer << '\n';
    return 0;
}