#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool flag = false;

void BFS(string origin, string target){
    queue<string> q;
    q.push(target);

    while(!q.empty()){
        string n = q.front();
        q.pop();

        if(n == origin){
            flag = true;
            return;
        }

        if(n.size() < origin.size()){
            flag = false;
            return;
        }

        if(n[n.size() - 1] == 'A'){
            string next1 = n.substr(0, n.size() - 1);
            q.push(next1);
        }

        if(n[0] == 'B'){
            reverse(n.begin(), n.end());
            string next2 = n.substr(0, n.size() - 1);
            q.push(next2);
        }
    }
}

int main() {
    FastIO();

    string s, t;
    cin >> s >> t;

    if(s.size() > t.size()){
        flag = false;
    }else{
        BFS(s, t);
    }

    if(flag){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}