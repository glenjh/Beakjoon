#include <iostream>
#include <stack>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    stack<int> s;
    int n, answer = 0;
    cin >> n;
    for(int i = 0 ; i <= n ; i++){
        int x, y;
        if(i < n){
            cin >> x >> y;
        }
        else{
            y = 0;
        }

        if(s.empty()){
            s.push(y);
        }
        else{
            while(!s.empty()){
                if(s.top() > y){
                    s.pop();
                    answer++;
                }else if(s.top() == y){
                    s.pop();
                }else if(s.top() < y){
                    break;
                }
            }
            s.push(y);
        }
    }
    cout << answer << '\n';

    return 0;
}