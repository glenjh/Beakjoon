#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector <int> v;
    for(int i = 0 ; i < 3 ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin() , v.end());

    for(auto it : v){
        cout << it << ' ';
    }
    return 0;
}