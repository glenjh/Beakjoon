#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, cnt = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        stack<char> s;
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            if(s.empty()){ s.push(input[j]); }
            else{
                if(s.top() == input[j]){
                    s.pop();
                }else{
                    s.push(input[j]);
                }
            }
        }
        if(s.empty()){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}