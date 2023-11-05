#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    for(int i = 0 ; i < 5 ; i++){
        int score;
        cin >> score;
        if(score < 40){
            score = 40;
        }
        sum += score;
    }

    cout << sum / 5;
}