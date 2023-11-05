#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    double answer = 1;
    cin >> n;
    string input;
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == 'S'){
            answer += 1;
        }
        else if(input[i] == 'L'){
            answer += 0.5;
        }
    }

    if(answer >= n){
        answer = n;
    }

    cout << answer << '\n';
    return 0;
}