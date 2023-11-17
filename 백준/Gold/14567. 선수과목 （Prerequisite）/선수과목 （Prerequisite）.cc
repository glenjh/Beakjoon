#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int arr[MAX];
int cnt[MAX];
vector<int> v[MAX];
queue<int> q;

void Topology(){
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == 0){
            cnt[i]++;
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(unsigned int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i];
            arr[next]--;
            cnt[next] = cnt[curr] + 1;
            if(arr[next] == 0){
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
        arr[b] += 1;
    }

    Topology();
    for(int i = 1 ; i <= n ; i++){
        cout << cnt[i] << ' ';
    }

    return 0;
}