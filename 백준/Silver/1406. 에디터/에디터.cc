#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    stack<char> s;
    stack<char> temp;
    string word = "", answer = "";
    cin >> word;

    for(const auto& i : word){
        s.push(i);    
    }

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;

        if(input == "L"){
            if(!s.empty()){
                temp.push(s.top());
                s.pop();
            }
        }
        else if(input == "D"){
            if(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(input == "B"){
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            char extra;
            cin >> extra;
            s.push(extra);
        }
    }

    while (!s.empty()){
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());

    while(!temp.empty()){
        answer += temp.top();
        temp.pop();
    }
    
    cout << answer << '\n';

    return 0;
}   