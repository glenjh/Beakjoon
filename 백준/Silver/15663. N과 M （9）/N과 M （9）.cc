#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
vector<int> v;
vector<int> lists;

bool visited[9];

set<vector<string>> s;

void DFS(int cnt){
    if(cnt == m){
        string temp = "";
        vector<string> minSet;

        for(int i = 0 ; i < lists.size() ; i++){
            cout << lists[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int chk = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && chk != v[i]){
            chk = v[i];
            lists.push_back(v[i]);
            visited[i] = true;

            DFS(cnt + 1);

            visited[i] = false;
            lists.pop_back();
        }
    }
}

int main() {
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