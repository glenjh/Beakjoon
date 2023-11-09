#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v[MAX];
queue<int> q;
int cnt[MAX];
int n, m;

bool visited[MAX];

void Sol(){
    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] == 0){
            q.push(i);
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(q.empty()){
            return;
        }

        int curr = q.front();
        cout << curr << ' ';
        q.pop();
        for(int j = 0 ; j < v[curr].size() ; j++){
            int next = v[curr][j];
            cnt[next] -= 1;
            if(cnt[next] == 0){
                q.push(next);
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        cnt[b]++;
    }

    Sol();

    return 0;
}