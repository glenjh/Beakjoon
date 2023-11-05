#include <iostream>
#include <vector>

using namespace std;

vector<int> v = {1, 5, 10, 50};
int n, ans = 0;

bool visited[1001];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int cnt, int start, int sum){
    if(cnt == n){
        if(!visited[sum]){
            visited[sum] = true;
            ans++;
        }
        return;
    }

    for(int i = start ; i < 4 ; i++){
        int nextSum = sum + v[i];
        DFS(cnt+1, i, nextSum);
    }
}

int main(){
    FastIO();

    cin >> n;

    DFS(0, 0, 0);

    cout << ans << '\n';

    return 0;
}