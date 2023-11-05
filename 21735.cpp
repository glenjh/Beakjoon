#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int arr[101];
int answer = 0;

bool visited[101];

void DFS(int x, int size, int time){
    if(time == m || x >= n){
        answer = max(answer, size);
        return;
    }

    if(x+1 <= n){
        if(!visited[x+1]){
            visited[x+1] = true;
            int nextSize = size + arr[x+1];
            DFS(x+1, nextSize, time+1);
            visited[x+1] = false;
        }
    }

    if(x+2 <= n){
        if(!visited[x+2]){
            visited[x+2] = true;
            int nextSize = size/2 + arr[x+2];
            DFS(x+2, nextSize, time+1);
            visited[x+2] = false;
        }
    }
}

int main(){
    FastIO();

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    DFS(0, 1, 0);

    cout << answer << '\n';

    return 0;
}