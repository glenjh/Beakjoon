#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string change(string a){
    string a_temp = "";
    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] == '1'){
            a_temp += "one";
        }else if(a[i] == '2'){
            a_temp += "two";
        }else if(a[i] == '3'){
            a_temp += "three";
        }else if(a[i] == '4'){
            a_temp += "four";
        }else if(a[i] == '5'){
            a_temp += "five";
        }else if(a[i] == '6'){
            a_temp += "six";
        }else if(a[i] == '7'){
            a_temp += "seven";
        }else if(a[i] == '8'){
            a_temp += "eight";
        }else if(a[i] == '9'){
            a_temp += "nine";
        }else if(a[i] == '0'){
            a_temp += "zero";
        }
    }
    return a_temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<string, int>> v;
    int m, n;
    cin >> m >> n;

    for(int i = m ; i <= n ; i++){
        string rel = change(to_string(i));
        v.push_back({rel, i});
    }

    sort(v.begin(), v.end());

    for(int i = 1 ; i <= v.size() ; i++){
        cout << v[i-1].second << ' ';
        if(i % 10 == 0){
            cout << '\n';
        }
    }
    return 0;
}