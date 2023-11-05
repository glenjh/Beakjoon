#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
vector<int> v;

bool visited[10];

void DFS(int idx, int cnt){
    if(cnt == m){
        for(int i = 0 ; i < n ; i++){
            if(visited[i]){
                cout << v[i] << ' ';
            }
        }
        cout << '\n';
        return;
    }

    for(int i = idx ; i < n ; i++){
        if(!visited[i]){
            visited[i] = true;
            DFS(i, cnt+1);
            visited[i] = false;
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

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    DFS(0, 0);

    return 0;
}