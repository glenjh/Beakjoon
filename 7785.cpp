#include <iostream>
#include <string>
#include <set>
#include <functional>

using namespace std;

int main(){
    int n;
    set<string, greater<string>> s;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string name, flag;
        cin >> name >> flag;
        if(flag == "enter"){
            s.insert(name);
        }else{
            s.erase(name);
        }
    }
    
    for(auto it : s){ cout << it << '\n'; }
    return 0;
}