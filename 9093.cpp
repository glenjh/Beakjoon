#include <iostream>
#include <stack>
#include <string>

using namespace  std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string input, result;
    cin >> n;
    cin.ignore();
    for(int i = 0 ; i < n ; i++){
        result = "";
        stack<char> s;
        getline(cin, input);
        
        for(int j = 0 ; j < input.length() ; j++){
            if(input[j] == ' '){
                while(!s.empty()){
                    result += s.top();
                    s.pop();
                }
                result += " ";
            }
            else{
                s.push(input[j]);
            }
        }
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        cout << result <<'\n';
    }
    return 0;
}