#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> s;
vector<string> v;
bool visited[11];

int n, k;

void DFS(string curr, int cnt){
    if(cnt == k){
        s.insert(curr);
        return;
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            string next = curr + v[i];
            DFS(next, cnt+1);
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

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        v.push_back(input);
    }

    string start = "";

    DFS(start, 0);
    
    cout << s.size() << '\n';

    return 0;
}