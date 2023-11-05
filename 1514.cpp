#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input, temp = "";
    bool minus_flag = false;
    int sum = 0, minus = 0;
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        if(input[0] == '-'){
            minus_flag = true;
        }

        if(isdigit(input[i])){
            temp += input[i];
        }
        else{
            if(minus_flag){
                minus -= stoi(temp);
            }else if(!minus_flag){
                sum += stoi(temp);
            }
            temp = "";

            if(input[i] == '-'){
                minus_flag = true;
            }
        }

        if(i == input.length() - 1){
            if(minus_flag){
                minus -= stoi(temp);
            }else{
                sum += stoi(temp);
            }
        }
    }
    cout << sum + minus << '\n';

    return 0;
}