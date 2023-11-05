#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, how_many_cows;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        stack <char> s;
        string cows;
        cin >> how_many_cows >> cows;
        
        for(int j = 0 ; j < cows.length() ; j++){
            if(s.empty()){ s.push(cows[j]); }
            else{
                if(s.top() == '>'){
                    if(cows[j] == '<'){
                        s.pop();
                    }else{
                        s.push(cows[j]);
                    }
                }
            }
        }
        if(s.empty()){ cout << "legal" << '\n'; }
        else{ cout << "illegal" << '\n'; }
    }
    return 0;
}