#include <iostream>
using namespace std;

long long get_xor(long long a){
    if(a%4 == 0){ return a; }
    else if(a%4 == 1){ return a ^ (a-1); }
    else if(a%4 == 2){ return a ^ (a-1) ^ (a-2); }
    else if(a%4 == 3){ return 0; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    
    cout << ( get_xor(b) ^ get_xor(a-1) ) << '\n';
    return 0;
}