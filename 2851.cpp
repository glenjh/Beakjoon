#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    for(int i = 0 ; i < 10 ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    int start = 1, diff = 100, answer;

    while(start <= 10){
        int sum = 0;

        for(int i = 0 ; i < start ; i++){
            sum += v[i];
        }
        if(abs(100 - sum) <= diff){
            diff = abs(100 - sum);
            answer = sum;
        }
        start++;
    }

    cout << answer << '\n';

    return 0;
}