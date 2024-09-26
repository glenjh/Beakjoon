#include <iostream>
#include <vector>
#include <set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
int arr[101];
vector<int> v[101];
set<int> ans;

bool visited[101];

void DFS(int start, int curr){
    if(visited[curr]){
        ans.insert(curr);
        return; 
    }
    visited[curr] = true;

    for(int i = 0 ; i < v[curr].size() ; i++){
        int next = v[curr][i];
        DFS(start, next);
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        v[i + 1].push_back(arr[i]);
    }
    
    for(int i = 0 ; i < n ; i++){
        DFS(i + 1, arr[i]);

        for(int j = 0 ; j < 101 ; j++){
            visited[j] = false;
        }
    }

    cout << ans.size() << '\n';
    for(auto it : ans){
        cout << it << '\n';
    }

    return 0;
}