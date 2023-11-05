#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    string input, boom, temp = "";
    cin >> input >> boom;

    for(int i = 0 ; i < input.length() ; i++){
        temp += input[i];
        bool flag = true;
        if(temp.length() >= boom.length()){
            
            for(int j = 0 ; j < boom.length() ; j++){
                
                if(boom[j] != temp[temp.length() - boom.length() + j]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                for (int k = 0; k < boom.length(); k++){
                    temp.pop_back();
                }
            }
        }
    }

    if(temp.length() == 0){
        cout << "FRULA" << '\n';
    }else{
        cout << temp << '\n';
    }

    return 0;
}