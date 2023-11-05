#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
int arr[9];

void DFS(int idx, int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx ; i < n ; i++){
        arr[cnt] = v[i];
        DFS(i, cnt+1); 
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

    sort(v.begin(), v.end());

    DFS(0, 0);

    return 0;
}