#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[10];
string arr[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
vector<string> v;
vector<string> ans;
vector<string> sign;

int n;
string m, M;

void DFS(int cnt){
    if(cnt == n + 1){
        string temp = "";
        for(int i = 0 ; i < v.size() ; i++){
            temp += v[i];
        }

        for(int i = 0 ; i < sign.size() ; i++){
            if(sign[i] == ">"){
                if(temp[i] - '0' < temp[i + 1] - '0') { return; }
            }
            else if(sign[i] == "<"){
                if (temp[i] - '0' > temp[i + 1] - '0') { return; }
            }
        }
        if(m == ""){
            m = temp;
        }
        else if(m != ""){
            M = temp;
        }

        return;
    }

    for(int i = 0 ; i < 10 ; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(arr[i]);
            DFS(cnt + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        sign.push_back(input);
    }

    DFS(0);

    cout << M << '\n' << m << '\n';

    return 0;
}