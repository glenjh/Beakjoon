#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        deque<int> d;

        bool flag = true;
        bool is_reversed = false;

        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        string temp = "";
        for(int i = 1 ; i < x.length() ; i++){
            if('0' <= x[i] && x[i] <= '9'){
                temp += x[i];
            }else if(x[i] == ',' || x[i] == ']'){
                if(!temp.empty()){
                    d.push_back(stoi(temp));
                    temp = "";
                }
                
            }
        }
        

        for(int i = 0 ; i < p.length() ; i++){
            if(p[i] == 'R'){
                is_reversed = !is_reversed;
            }
            else if(p[i] == 'D'){
                if(d.empty()){
                    cout << "error" << '\n';
                    flag = false;
                    break;
                }
                if(is_reversed){ d.pop_back(); }
                else{ d.pop_front(); }
            }
        }

        if(flag){
            if(!is_reversed){
                cout << '[';
                for(int i = 0 ; i < d.size() ; i++){
                    cout << d[i];
                    if(i != d.size() - 1){
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
            else{
                cout << '[';
                for(int i = d.size()-1 ; i >= 0 ; i--){
                    cout << d[i];
                    if(i != 0){
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
            
        }
    }
    return 0;
}