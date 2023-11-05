#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string input;
    while(true){
        bool flag = true;
        stack<char> s;
        getline(cin , input);
        if(input[0] == '.'){ break; }
        for(int i=0 ; i<input.size() ; i++){
            if(input[i] == '('){ s.push(input[i]); }
            else if(input[i] == ')'){
                if(s.empty() == false && s.top() == '('){ s.pop(); }
                else{ 
                    flag = false;
                    break; 
                }
            }

            else if(input[i] == '['){ s.push(input[i]); }
            else if(input[i] ==']'){ 
                if(s.empty() == false && s.top() == '['){ s.pop(); }
                else{ 
                    flag = false;
                    break; 
                }
            }
        }
        if(s.empty() == true && flag == true){ cout << "yes" << '\n'; }
        else{ cout << "no" << '\n'; }
    }
    return 0;
}