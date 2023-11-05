#include <iostream>
#include <vector>

using namespace std;

int a, b, cnt = 0, mini = 1000, curr, answer = 1;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int easy = abs(a - b);

    int n;
    vector<int> v;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int number;
        cin >> number;
        v.push_back(number);

        if(number == b){
            cout << 1 << '\n';
            return 0;
        }
    }

    for(int i = 0 ; i < v.size() ; i++){
        int temp = abs(b - v[i]);
        if(temp < mini){
            mini = temp;
            curr = v[i];
        }
    }

    if(easy <= mini){
        answer = easy;

    }else{
        answer += abs(b - curr);
    }
    cout << answer << '\n';

    return 0;
}