#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int answer = 0;

    string l, r;
    cin >> l >> r;

    if(l.size() == r.size()){
        for(int i = 0 ; i < l.length() ; i++){
            if(l[i] == r[i] && l[i] == '8'){
                answer += 1;
            }else if(l[i] != r[i]){
                break;
            }
        }
    }else{
        answer = 0;
    }
    cout << answer << '\n';

    return 0;
}