#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    for(int i = 0  ; i < n ; i++){
        stack<string> s;
        string input, answer = "", word="";
        getline(cin , input);

        for(int j = 0 ; j < input.length() ; j++){
            if(input[j] == ' '){
                s.push(word);
                s.push(" ");
                word = "";
            }else{ word += input[j]; }
        }
        s.push(word);

        while(!s.empty()){
            answer += s.top();
            s.pop();
        }
        cout << "Case #" << i+1 << ": " << answer << '\n';
    }
    return 0;
}