#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(int a, int b){
    return a < b;
}

int n, m;
int arr[8];
vector<int> v;

bool visited[8];

void DFS(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++){
        arr[cnt] = v[i];
        DFS(cnt+1);
    }
}

int main(){
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    DFS(0);

    return 0;
}