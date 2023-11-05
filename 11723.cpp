#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set <int> new_set = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    set <int> s;
    string command;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> command;
        int input;
        if(command == "add"){
            cin >> input;
            if(s.find(input) == s.end()){ s.insert(input); }
        }

        else if(command == "remove"){
            cin >> input;
            if(s.find(input) != s.end()){
                s.erase(input);
            }
        }

        else if(command == "check"){
            cin >> input;
            if(s.find(input) == s.end()){ cout << 0 << '\n'; }
            else{ cout << 1 << '\n'; }
        }

        else if(command == "toggle"){
            cin >> input;
            if(s.find(input) == s.end()){
                s.insert(input);
            }else{
                s.erase(input);
            }
        }

        else if(command == "all"){
            s = new_set;
        }

        else {
            s.clear();
        }
    }

    return 0;
}