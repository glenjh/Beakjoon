#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s , rel = "";
    stack<char> ss;
    getline(cin , s);

    for(int i=0 ; i<s.length() ; i++){
        if(s[i] == ' '){
            while(!ss.empty()){
                rel += ss.top();
                ss.pop();
            }
            rel += ' ';
        }
        else if(s[i] == '<'){
            while(!ss.empty()){
                rel += ss.top();
                ss.pop();
            }
            while(true){
                if(s[i] == '>'){ 
                    rel += '>';
                    break; 
                }
                rel += s[i];
                i++;
            }
        }

        else{
            ss.push(s[i]);
        }

        if(i == s.length()-1){
            while(!ss.empty()){
                rel += ss.top();
                ss.pop();
            }
        }
    }

    cout << rel;
    return 0;
}