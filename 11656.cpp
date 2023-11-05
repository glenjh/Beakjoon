#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v;
    string input;
    cin >> input;

    int start_point = 0;

    for(int i = start_point ; i < input.length() ; i++){
        string temp = "";
        for(int j = i ; j < input.length() ; j++){
            temp += input[j];
        }
        v.push_back(temp);
    }    

    sort(v.begin() , v.end());

    for(auto it : v){
        cout << it << '\n';
    }

    return 0;
}