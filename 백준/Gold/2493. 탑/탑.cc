#include <iostream>
#include <stack>
#define MAX 500001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    stack<pair<int, int>> s; // idx, value
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int input;
        cin >> input;

        while(!s.empty()){
            if(s.top().second > input){
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }

        if(s.empty()){
            cout << 0 << ' ';
        }

        s.push({i, input});
    }

    return 0;
}