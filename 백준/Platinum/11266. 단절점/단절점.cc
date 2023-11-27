#include <iostream>
#include <vector>
#include <set>
#define MAX 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v[MAX];
set<int> s;
int visited[MAX];
int cnt;

int DFS(int curr, bool isRoot){
    visited[curr] = ++cnt;
    int fastest = visited[curr];
    int child = 0;

    for(int i = 0 ; i < v[curr].size() ; i++){
        int next = v[curr][i];

        if(visited[next] == -1){
            child++;
            int subTree = DFS(next, false);
            if(!isRoot && visited[curr] <= subTree){
                s.insert(curr);
            }
            fastest = min(fastest, subTree);
        }
        else{
            fastest = min(fastest, visited[next]);
        }
    }

    if(isRoot && child > 1){
        s.insert(curr);
    }

    return fastest;
}

int main() {
    FastIO();

    int n, m;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        visited[i] = -1;
    }

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        if(visited[i] == -1){
            DFS(i, true);
        }
    }

    cout << s.size() << '\n';
    for(auto it : s){
        cout << it << ' ';
    }

    return 0;
}