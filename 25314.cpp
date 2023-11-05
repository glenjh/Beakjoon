#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string answer = "";
    cin >> n;

    for(int i = 0 ; i < n/4 ; i++){
        answer += "long ";
    }   

    answer += "int";
    cout << answer << '\n';

    return 0;
}