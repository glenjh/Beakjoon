#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    else if(a.length() == b.length()){
        int a_cnt = 0, b_cnt = 0;
        for(int i = 0 ; i< a.length() ; i++){
            if(isdigit(a[i])){
                a_cnt += a[i] - '0';
            }
        }

        for(int i = 0 ; i< b.length() ; i++){
            if(isdigit(b[i])){
                b_cnt += b[i] - '0';
            }
        }

        if(a_cnt != b_cnt){
            return a_cnt < b_cnt;
        }else{
            return a < b;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    for(auto it : v){
        cout << it << '\n';
    }
    return 0;
}