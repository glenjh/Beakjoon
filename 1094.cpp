#include <iostream>

using namespace std;

int main(){
    int x, cnt = 0;
    cin >> x;

    string rel;
    while(x != 0){
        rel += to_string(x%2);
        x = x/2;
    }
    
    for(auto it : rel){
        if(it == '1'){ cnt+=1; }
    }
    cout << cnt;
    return 0;
}