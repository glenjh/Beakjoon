#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

unordered_multiset<long long> s;

void BFS(long long x, long long cnt){
    queue<pair<long long, long long>> q;
    q.push({x, cnt});
    s.insert(x);

    while(!q.empty()){
        long long curr = q.front().first;
        long long currCnt = q.front().second;
        q.pop();

        if(curr == 1){
            cout << currCnt << '\n';
            return;
        }

        if(curr%3 == 0 && s.find(curr/3) == s.end()){
            s.insert(curr / 3);
            q.push({curr / 3, currCnt+1});
        }

        if (curr % 2 == 0 && s.find(curr/2) == s.end()){
            s.insert(curr / 2);
            q.push({curr / 2, currCnt+1});
        }

        if(curr > 1 && s.find(curr-1) == s.end()){
            s.insert(curr-1);
            q.push({curr-1, currCnt+1});
        }
    }
}

int main(){
    FastIO();

    long long n;
    cin >> n;

    BFS(n, 0);

    return 0;
}