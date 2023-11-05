#include <iostream>
#include <vector>

using namespace std;

bool visited[100001];
int arr[100001];

vector<int> v[100001];

void DFS(int parent){
    if(visited[parent]){ return; }
    visited[parent] = true;

    for(int i = 0 ; i < v[parent].size() ; i++){
        int child = v[parent][i];
        if(!visited[child]){
            arr[child] = parent;
            DFS(child);
        }
    }
}

int main(){
    int n, p, c;
    cin >> n;

    for(int i = 0 ; i < n-1 ; i++){
        cin >> p >> c;
        v[p].push_back(c);
        v[c].push_back(p);
    }

    DFS(1);

    for(int i = 2 ; i <= n ; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}