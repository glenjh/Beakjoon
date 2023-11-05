#include <iostream>
#include <queue>

using namespace std;

int n, answer;
bool visited[1000001];

void BFS(int x){
    queue<pair<int,int>> q;
    q.push({x, 0});
    visited[x] = true;

    while (!q.empty()){
        int first = q.front().first, cnt = q.front().second;
        q.pop();

        if(first == 1){
            answer = cnt;
            return;
        }

        if(first % 3 == 0 && !visited[first%3]){
            q.push({first/3, cnt+1});
            visited[first/3] = true;
        }
        if(first % 2 == 0 && !visited[first%2]){
            q.push({first/2, cnt+1});
            visited[first/2] = true;
        }
        if(!visited[first - 1]){
            q.push({first-1 , cnt+1});
            visited[first-1] = true;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    BFS(n);
    cout << answer;
    return 0;
}