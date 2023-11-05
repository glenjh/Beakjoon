#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char arr[4] = {'U', 'C', 'P', 'C'};
    string input;
    getline(cin, input);

    int pivot = 0, cnt = 0;

    for(int i = 0 ; i < 4 ; i++){
        for(int j = pivot ; j < input.length() ; j++){
            if(input[j] == arr[cnt]){
                pivot = j;
                cnt++;
            }
        }
    }

    if(cnt == 4){
        cout << "I love UCPC" << '\n';
    }else{
        cout << "I hate UCPC" << '\n';
    }

    return 0;
}