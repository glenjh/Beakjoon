#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int l, c;

vector<string> v;
vector<string> password;

bool visited[16];

void DFS(int cnt){
    if(cnt == l){
        int elseCnt = 0;
        int cnt = 0;
        for(int i = 0 ; i < password.size() ; i++){
            string c = password[i];

            if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u"){
                cnt += 1;
            }else{
                elseCnt += 1;
            }
        }

        if(cnt >= 1 && elseCnt >= 2){
            for(int i = 0 ; i < password.size() ; i++){
                cout << password[i];
            }
            cout << '\n';
        }
    }

    for(int i = 0 ; i < c ; i++){
        if(!visited[i]){
            if(password.empty()){
                password.push_back(v[i]);
                visited[i] = true;
                DFS(cnt + 1);
                visited[i] = false;
                password.pop_back();
            }
            else{
                if(password[password.size() - 1] < v[i]){
                    password.push_back(v[i]);
                    visited[i] = true;
                    DFS(cnt + 1);
                    visited[i] = false;
                    password.pop_back();
                }
            }
        }
    }
}

int main() {
    FastIO();

    cin >> l >> c;
    for(int i = 0 ; i < c ; i++){
        string input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    DFS(0);

    return 0;
}