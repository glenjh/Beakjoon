#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, answer = "";
    int x_len = 0;
    bool flag = true;
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == 'X'){
            x_len += 1;
        }
        if(input[i] == '.' || i == input.length() - 1){
            if(x_len % 2 != 0){
                flag = false;
                break;
            }

            while (x_len != 0){
                if(x_len < 4){
                    answer += "BB";
                    x_len -= 2;
                }else{
                    answer += "AAAA";
                    x_len -= 4;
                }
            }

            if(input[i] == '.'){
                answer += '.';
            }
        }
    }
    if(!flag){
        cout << -1 << '\n';
    }else{
        cout << answer << '\n';
    }

    return 0;
}