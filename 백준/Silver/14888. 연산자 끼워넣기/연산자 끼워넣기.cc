#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, len, m  = INT_MAX, M = INT_MIN;
vector<int> v;
int arr[4]; // +, -, *, /

vector<string> signs;
vector<string> lists;

bool visited[12];

void DFS(int cnt){
    if(cnt == len){
        int temp = v[0], idx = 1;

        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] == "+"){
                temp += v[idx];
            }
            else if(lists[i] == "-"){
                temp -= v[idx];
            }
            else if (lists[i] == "*"){
                temp *= v[idx];
            }
            else if (lists[i] == "/"){
                temp /= v[idx];
            }
            idx++;
        }
        M = max(M, temp);
        m = min(m, temp);
    }

    for(int i = 0 ; i < signs.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            lists.push_back(signs[i]);
            DFS(cnt + 1);
            lists.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0 ; i < 4 ; i++){
        cin >> arr[i];
        string input;
        if(arr[i] > 0){
            if(i == 0){
                input = "+";
            }
            else if(i == 1){
                input = "-";
            }
            else if(i == 2){
                input = "*";
            }
            else if(i == 3){
                input = "/";
            }

            for(int j = 0 ; j < arr[i] ; j++){
                signs.push_back(input);
            }
        }
        len += arr[i];
    }

    DFS(0);

    cout << M << '\n' << m <<'\n';

    return 0;
}