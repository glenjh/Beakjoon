#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, answer = 0;
    cin >> n >> k;

    string input;
    cin >> input;

    bool eaten[20001] = {false, };

    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] == 'P'){
            for(int j = i-k ; j <= i+k ; j++){
                if(input[j] == 'H'){
                    if(!eaten[j]){
                        eaten[j] = true;
                        answer += 1;
                        break;
                    }    
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}