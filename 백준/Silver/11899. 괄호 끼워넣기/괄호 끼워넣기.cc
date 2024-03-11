#include <iostream>
#include <stack>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int answer = 0;
    stack<char> s;
    string input;
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        char c = input[i];
        if(s.empty()){
            s.push(c);
            answer += 1;
        }
        else{
            if(c == ')'){
                if(s.top() == '('){
                    answer -= 1;
                    s.pop();
                }else{
                    answer += 1;
                    s.push(c);
                }
            }
            else if(c == '('){
                answer += 1;
                s.push(c);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}