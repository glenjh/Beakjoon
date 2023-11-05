#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int n;
int k;
int answer = -1;

set<string> s[11];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(string n, int cnt){
    queue<pair<string, int>> q;
    q.push({n, cnt});

    while(!q.empty()){
        string currN = q.front().first;
        int currCnt = q.front().second;
        q.pop();

        if(currCnt == k){
            answer = max(stoi(currN), answer);
            continue;
        }

        for(int i = 0 ; i < n.length()-1 ; i++){
            for(int j = i+1 ; j < n.length() ; j++){
                string temp = currN;
                swap(temp[i], temp[j]);
                if(temp[0] == '0'){ continue; }

                if(s[currCnt].find(temp) == s[currCnt].end()){
                    s[currCnt].insert(temp);
                    q.push({temp, currCnt+1});
                }
                swap(temp[i], temp[j]);
            }
        }
    }
}

int main(){
    FastIO();

    cin >> n >> k;
    string s = to_string(n);
    BFS(s, 0);

    cout << answer << '\n';

    return 0;
}