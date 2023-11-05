#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;

        if(6 <= input.length() && input.length() <= 9){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
    }

    return 0;
}