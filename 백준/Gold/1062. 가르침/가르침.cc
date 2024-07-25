#include <iostream>
#include <vector>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[26];

vector<string> v;
int n, k, answer;

void DFS(int cnt, int idx){
    if(cnt == k){
        int cnt = 0;
        string temp = "";

        for(int i = 0 ; i < n ; i++){
            bool flag = true;
            for(int j = 0 ; j < v[i].length() ; j++){
                if(!visited[v[i][j] - 'a']){
                    flag = false;
                    break;
                }
            }
            if(flag){ cnt += 1; }
        }
    
        answer = max(answer, cnt);
        return;
    }
    
    for(int i = idx ; i < 26 ; i++){
        if(!visited[i]){
            visited[i] = true;
            DFS(cnt + 1, i);
            visited[i] = false;
        }
    }
}

int main() {
    FastIO();
    
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        string input, temp = "";
        cin >> input;

        for(int j = 0 ; j < input.length() ; j++){
            if (input[j] != 'a' && input[j] != 'n' && input[j] != 't' && input[j] != 'i' && input[j] != 'c'){
                temp += input[j];
            }
        }   

        v.push_back(temp);
    }

    if(k < 5){
        answer = 0;
    }
    else{
        visited[(int)'a' - 97] = true;
        visited[(int)'n' - 97] = true;
        visited[(int)'t' - 97] = true;
        visited[(int)'i' - 97] = true;
        visited[(int)'c' - 97] = true;
        DFS(5, 0);
    }

    cout << answer << '\n';

    return 0;
}