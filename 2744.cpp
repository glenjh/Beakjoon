#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input, temp  = "";
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        if(islower(input[i])){
            temp += toupper(input[i]);
        }else{
            temp += tolower(input[i]);
        }
    }

    cout << temp << '\n';

    return 0;
}