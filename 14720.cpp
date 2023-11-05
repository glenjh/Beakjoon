#include <iostream>

using namespace std;

int main(){
    int t, cnt = 0, milk, curr = 0;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        cin >> milk;
        if(milk == curr){
            cnt++;
            curr++;
            if(curr > 2){
                curr = 0;
            }
        }
    }
    cout << cnt;
    return 0;
}