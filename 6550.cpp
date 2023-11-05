#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;

    while(cin >> s >> t){
        int pivot = -1, cnt = 0;

        for(int i = 0 ; i < s.length() ; i++){
            for(int j = pivot + 1 ; j < t.length() ; j++){
                if(s[i] == t[j]){
                    pivot = j;
                    cnt++;
                    break;
                }
            }
        }
        
        if(cnt == s.size()){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }

    return 0;
}