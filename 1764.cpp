#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    set<string> hear;
    set<string> see;
    set<string> h_s;
    string h,s;
    for(int i=0 ; i<n ; i++){
        cin >> h;
        hear.insert(h);
    }
    for(int i=0 ; i<m ; i++){
        cin >> s;
        see.insert(s);
    }
    for(auto i : hear){
        if(see.find(i) != see.end()){
            h_s.insert(i);
        }
    }
    cout << h_s.size() << '\n';
    for(auto i : h_s){
        cout << i << '\n';
    }
    return 0;
}