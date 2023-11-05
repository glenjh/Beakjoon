#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    unordered_set<string> myset;
    cin >> s;
    for(int i=1 ; i<=s.length() ; i++){
        for(int j=0 ; j<s.length() ; j++){
            string sub = s.substr(j,i);
            myset.insert(sub); 
        }
    }

    cout << myset.size();
    return 0;
}