# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
string a,b;


string sum(string a, string b){
    int carry = 0;
    string rel_string;
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    for(int i=0 ; i<b.length() ; i++){
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        if(sum >= 10){
            sum-=10;
            carry = 1;
        }else{ carry = 0; }
        rel_string += to_string(sum);
    } 

    for(int i=b.length() ; i<a.length() ; i++){
        int sum = (a[i]-'0') + carry;
        if(sum >= 10){
            sum -= 10;
            carry = 1;
        }else{ carry = 0; }
        rel_string += to_string(sum);
    }
    if(carry == 1){ rel_string += "1"; }
    reverse(rel_string.begin() , rel_string.end());
    return rel_string;
}

int main(){
    string tmp;
    cin >> a >> b;
    if(a.length() < b.length()){
        tmp = a;
        a = b;
        b = tmp;
    }
    string rel = sum(a,b);
    for(int i=0 ; i<rel.length() ; i++){
        cout << rel[i] - '0';
    }
    return 0;
}