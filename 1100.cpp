#include <iostream>
using namespace std;

int main(){
    char arr[8][8];
    int cnt = 0;
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            if(arr[i][j] == 'F' && (i+j)%2 == 0){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}