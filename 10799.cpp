#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    stack<char> s;
    string input;
    cin >> input;

    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            if(input[i-1] == '('){
                s.pop();
                answer += s.size();
            }
            else if(s.top() == '('){
                s.pop();
                answer += 1;
            }
            
        }
    }

    cout << answer << '\n';
    

    return 0;
}