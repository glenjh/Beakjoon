#include <iostream>
using namespace std;

int main(){
    int input , cnt_1 = 0;
    for(int i = 0 ; i < 3 ; i++){
        int cnt_0 = 0;
        for(int j = 0 ; j < 4 ; j++){
            cin >> input;
            if(input == 0){cnt_0 += 1;}
        }
        if(cnt_0 == 0){
            cout << 'E' << '\n';
        }else if(cnt_0 == 1){
            cout << 'A' << '\n';
        }else if(cnt_0 == 2){
            cout << 'B' << '\n';
        }else if(cnt_0 == 3){
            cout << 'C' << '\n';
        }else{
            cout << 'D' << '\n';
        }
    }
    return 0;
}