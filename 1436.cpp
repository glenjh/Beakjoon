#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i= 666;;i++){
        if(to_string(i).find("666") != string::npos){
            cnt++;
        }
        if(n == cnt){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}