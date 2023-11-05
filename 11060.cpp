#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int cnt[1001] = {0, };
vector<int> v;

bool visited[1001];

void BFS(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        int how_much_move = v[curr];
        for(int i = 0 ; i <= how_much_move ; i++){
            int next = curr + i;
            if(next >= n){ continue; }
            if(!visited[next]){
                visited[next] = visited[curr] + 1;
                cnt[next] = cnt[curr] + 1;
                q.push(next);
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    BFS(0);

    if(cnt[n-1] == 0 && v.size() != 1){
        cout << -1 << '\n';
    }else{
        cout << cnt[n-1] << '\n'; 
    }

    return 0;
}