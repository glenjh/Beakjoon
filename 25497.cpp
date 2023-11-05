#include <iostream>
#include <stack>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    stack<char> LR;
    stack<char> SK;

    int n, cnt = 0;
    cin >> n;
    string input;
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        if('1' <= input[i] && input[i] <= '9'){
            cnt++;
        }

        else{
            if(input[i] == 'L'){
                LR.push(input[i]);
            }else if(input[i] == 'S'){
                SK.push(input[i]);
            }else if(input[i] == 'R'){
                if(LR.empty()){
                    break;
                }else{
                    cnt += 1;
                    LR.pop();
                }
            }else if(input[i] == 'K'){
                if(SK.empty()){
                    break;
                }else{
                    cnt += 1;
                    SK.pop();
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}