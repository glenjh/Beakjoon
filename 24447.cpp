#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long seqs[100001] = {0, }; //방문순서
long long dist[100001] = {-1,}; //거리

long long n, m, r, seq = 1, answer;

vector<long long> v[100001];
bool visited[100001];

void BFS(long long start){
    queue<long long> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        long long curr = q.front();
        q.pop();

        seqs[curr] += seq;
        seq++;

        for(long long i = 0 ; i < v[curr].size() ; i++){
            long long next = v[curr][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[curr] + 1;
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

    cin >> n >> m >> r;

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0 ; i < 100001 ; i++){
        sort(v[i].begin(), v[i].end());
    }

    BFS(r);

    for(int i = 1 ; i <= n ; i++){
        answer += seqs[i] * dist[i];
    }

    cout << answer << '\n';

    return 0;
}