#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
vector<pair<int, int>> temp;
int cnt = 0;
int M = 0;
int answer = 0;

bool visited[1001];

void clear(){
    for(int i = 0 ; i < 1001 ; i++){
        visited[i] = false;
        cnt = 0;
    }
}

void DFS(int x){
    if(visited[x]){ return; }
    visited[x] = true;
    cnt++;

    for(int i = 0 ; i < v[x].size() ; i++){
        int child = v[x][i];
        if(!visited[child]){
            DFS(child);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        int input;
        cin >> input;
        v[i].push_back(input);
    }

    for(int i = 1 ; i <= t ; i++){
        DFS(i);
        temp.push_back({i, cnt});
        clear();
    }

    for(auto it : temp){
        if(it.second > M){
            M = it.second;
            answer = it.first;
        }
    }
    cout << answer << '\n';

    return 0;
}