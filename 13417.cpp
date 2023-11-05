#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(string a, string b){
    return a < b;
}

int main(){
    FastIO();

    int t;
    cin >> t;

    for(int testcast = 0 ; testcast < t ; testcast++){
        vector<string> v;
        int n;
        string temp = "";
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            string input;
            cin >> input;
            
            if(temp == ""){
                temp += input;
            }
            else{
                string front = input + temp;
                string back = temp + input;
                temp = min(front, back);
            }
        }
        cout << temp << '\n';
    }

    return 0;
}