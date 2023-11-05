#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    int n, cnt = 0, input;
    int max = 0;
    stack<int> s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input;
        s.push(input);
    }
    while(s.size()){
        for(int i=n-1;i>=0;i--){
            if(max < s.top()){
                cnt++;
                max = s.top();
            }
            s.pop();
        }
    }
    cout << cnt << endl;
    return 0;
}