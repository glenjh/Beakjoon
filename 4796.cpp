#include <iostream>

 using namespace std;

 int main(){
    int l, p, v, case_num = 1
    ;

    while(true){
        int answer = 0;

        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0){ break; }

        answer += (v / p) * l;

        if( (v % p) > l ){ answer += l; }
        else{ answer += v % p; }
        
        cout << "Case " << case_num << ": " << answer << '\n';
        case_num++;

    }
    return 0;
 }