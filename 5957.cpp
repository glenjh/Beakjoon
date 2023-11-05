#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> dishes, washed, dried;
    int n;

    cin >> n;
    for(int i = n ; i >= 1 ; i--){
        dishes.push(i);
    }

    int c_i, d_i;

    while(dried.size() != n){
        cin >> c_i >> d_i;
        if(c_i == 1){
            while(d_i){
                washed.push(dishes.top());
                dishes.pop();
                d_i -= 1;
            }
        }else{
            while(d_i){
                dried.push(washed.top());
                washed.pop();
                d_i -= 1;
            }
        }
    }
    
    while(!dried.empty()){
        cout << dried.top() << '\n';
        dried.pop();
    }
    return 0;
}