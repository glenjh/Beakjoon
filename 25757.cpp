#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    unordered_set<string> s;
    int n, answer;
    string game;
    cin >> n >> game;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        s.insert(input);
    }


    if(game == "Y"){
        if(s.size() < 1){
            answer = 0;
        }else{
            answer = s.size();
        }
    }else if(game == "F"){
        if(s.size() < 2){
            answer = 0;
        }else{
            answer = s.size() / 2;
        }
    }else{
        if(s.size() < 3){
            answer = 0;
        }else{
            answer = s.size() / 3;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}