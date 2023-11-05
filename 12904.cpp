#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool flag = false;
    string s, t;
    cin >> s >> t;
   
   while(t.length() >= s.length()){
        if(s == t){
            flag = true;
            break;
        }
        if(t[t.length() - 1] == 'A'){
            t.pop_back();
        }
        else if(t[t.length() - 1] == 'B'){
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    if(flag){
        cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }

    return 0;
}