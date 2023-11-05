#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();
    
    string answer = "";
    stack<int> s;
    int n, lastPush = 1;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;

        while(lastPush <= input){
            s.push(lastPush);
            lastPush++;
            answer += "+";
        }

        if(s.top() == input){
            s.pop();
            answer += "-";
        }
        else{
            cout << "NO" << '\n';
            return 0;
        }
    }

    for(int i = 0 ; i < answer.length() ; i++){
        cout << answer[i] << '\n';
    }

    return 0;
}