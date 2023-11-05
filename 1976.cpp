#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
vector<int> v[201];

bool visited[201];

void reset(){
    for(int i = 0 ; i < 201 ; i++){
        visited[i] = false;
    }
}

bool BFS(int a, int b){
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == b){
            return true;
        }

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main(){
    FastIO();

    cin >> n >> m;
    string answer = "YES";

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int input;
            cin >> input;
            if(input == 1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    vector<int> city;
    for(int i = 0 ; i < m ; i++){
        int input;
        cin >> input;
        city.push_back(input);
    }

    for(int i = 0 ; i < city.size()-1 ; i++){
        bool flag = BFS(city[i], city[i+1]);
        if(!flag){
            answer = "NO";
        }
        reset();
    }

    cout << answer << '\n';

    return 0;
}