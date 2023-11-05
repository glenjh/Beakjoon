# include <iostream>
#include <climits>
using namespace std;

int main(){

    for(int i=0 ; i<3 ; i++){
        int testcase;
        long long sum = 0, input, overflowed = 0;
        cin >> testcase;
        for(int j=0 ; j<testcase ; j++){
            cin >> input;
            if(sum>0 && input>0 && sum>LLONG_MAX-input){
                overflowed++;
            }if(sum<0 && input<0 && sum<LLONG_MIN-input){
                overflowed--;
            }
            sum += input;
        }
        if(overflowed > 0){ cout << "+" << endl; }
        else if(overflowed < 0){
            cout << "-" << endl;
        }else{ 
            if(sum > 0){
                cout << "+" << endl;
            }else if(sum < 0){
                cout << "-" << endl;
            }else{
                cout << "0" << endl;
            }
        }
    }
    return 0;
}