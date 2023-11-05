#include <iostream>
#include <queue>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string answer = "";

bool visited[1000001] = {false, };

void BFS(int s, int target, string rel){
    queue<pair<int, string>> q;
    q.push({s, rel});
    visited[s] = true;

    while(!q.empty()){
        int curr = q.front().first;
        string temp = q.front().second;
        q.pop();

        if(curr == target){
            answer = temp;
            cout << answer << '\n';
            return;
        }

        int d = (curr * 2) % 10000;
        if(!visited[d]){
            q.push({d, temp + "D"});
            visited[d] = true;
        }

        int s = curr - 1;
        if(curr == 0){
            s = 9999;
        }
        if(!visited[s]){
            q.push({s, temp + "S"});
            visited[s] = true;
        }

        int l = (curr % 1000) * 10 + (curr / 1000);
        if(!visited[l]){
            q.push({l, temp + "L"});
            visited[l] = true;
        }

        int r = (curr % 10) * 1000 + (curr / 10); 
        if(!visited[r])
        {
            q.push({r, temp + "R"});
            visited[r] = true;
        }
    }
}

void Reset(){
    for(int i = 0 ; i < 100001 ; i++){
        visited[i] = false;
    }
    answer = "";
}

int main() {
    FastIO();

    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        int a, b;
        cin >> a >> b;

        BFS(a, b, "");
        Reset();
    }

    return 0;
}