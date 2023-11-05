#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input; 
    int sum = 0;

    bool flag = false;

    for(auto it : input){
        if(it == '0'){ flag = true; }
        sum += it - '0';
    }
    if(sum % 3 != 0){
        flag = false;
    }

    if(!flag){
        cout << -1 << '\n';
        return 0;
    }

    sort(input.begin(), input.end());
    reverse(input.begin(), input.end());

    cout << input << '\n';
    
    return 0;
}