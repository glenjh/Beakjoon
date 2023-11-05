#include <iostream>
#include <string>

using namespace std;

int zero(string input){
    int cnt = 0;
    bool flag = true;

    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == '0'){
            if(!flag){
                cnt += 1;
            }
            flag = true;
        }
        else{
            flag = false;
        }

        if(i == input.length() - 1){
            if(!flag){
                cnt += 1;
            }
        }
    }
    return cnt;
}

int one(string input){
    int cnt = 0;
    bool flag = true;

    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == '1'){
            if(!flag){
                cnt += 1;
            }
            flag = true;
        }
        else{
            flag = false;
        }

        if(i == input.length() - 1){
            if(!flag){
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count_0 = 0, count_1 = 0, cnt = 0;
    string input; 
    cin >> input;

    for(auto it : input){
        if(it == '0'){ count_0 += 1; }
        else{ count_1 += 1; }
    }

    if(count_0 == 0 || count_1 == 0){
        cout << 0 << '\n';
        return 0;
    }

    if(zero(input) > one(input)){
        cout << one(input) << '\n';
    }else{
        cout << zero(input) << '\n';
    }
    return 0;
}