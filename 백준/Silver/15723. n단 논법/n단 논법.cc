#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[27];
string ans;

vector<int> v[27];

void DFS(int start, int end){
    for(int i = 0 ; i < 27 ; i++){
        visited[i] = false;
    }

    if(visited[start]){ return; }
    visited[start] = true;

    if(start == end){
        ans = "T";
        return;
    }

    for(int i = 0 ; i < v[start].size() ; i++){
        int next = v[start][i];
        if(!visited[next]){
            DFS(next, end);
        }
    }
}

int main() {
    FastIO();

    int n, m;
    cin >> n;
    cin.ignore();

    for(int i = 0 ; i < n ; i++){
        string s;
        getline(cin, s);
        
        int start = s[0] - 'a';
        int end = s[s.length() - 1] - 'a';
        v[start].push_back(end);
    }

    cin >> m;
    cin.ignore();
    for(int i = 0 ; i < m ; i++){
        string s;
        getline(cin, s);
        int start = s[0] - 'a';
        int end = s[s.length() - 1] - 'a';
        ans = "F";
        DFS(start, end);
        cout << ans << '\n';
    }

    return 0;
}