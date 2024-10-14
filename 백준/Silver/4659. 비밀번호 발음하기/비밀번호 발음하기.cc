#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    while(true){
        bool flag = true;
        int mustCnt = 0, continueMust = 0, continueElse = 0, continu = 0;
        string input;
        cin >> input;

        if(input == "end"){ break; }

        for(int i = 0 ; i < input.length() ; i++){
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
                continueMust += 1;
                continueElse = 0;
                mustCnt += 1;
            }
            else{
                continueMust = 0;
                continueElse += 1;
            }

            if(continueMust >= 3 || continueElse >= 3){
                flag = false;
            }
        }

        bool flag2 = true;
        for(int i = 0 ; i < input.length() - 1 ; i++){
            string temp = "";
            if(input[i] == input[i + 1]){
                temp += input[i];
                temp += input[i + 1];
            }
            if(temp != ""){
                if(!(temp == "ee" || temp == "oo")){
                    flag = false;
                }
            }
        }

        cout << "<" << input << ">";
        if(mustCnt > 0 && flag && flag2){
            cout << " is acceptable." << '\n';
        }
        else{
            cout << " is not acceptable." << '\n';
        }

    }

    return 0;
}