#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[10];
int n, m;

bool visited[9];

void DFS(int idx){
    if(idx == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++){
        if (!visited[i]){
            arr[idx] = v[i];
            visited[i] = true;
            DFS(idx + 1);
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

    DFS(0);

    return 0;
}