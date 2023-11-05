#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag = false;
    for(int i = 0 ; i < 5 ; i++){
        string input;
        cin >> input;
        if(input.find("FBI") != string::npos){
            cout << i + 1 << ' ';
            flag = true;
        }
    }

    if(!flag){
        cout << "HE GOT AWAY!" << '\n';
    }
    return 0;
}