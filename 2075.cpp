#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int> , greater<int>> q;
    cin >> n;

    for(int i = 0 ; i < n * n ; i++){
        cin >> input;
        if(q.size() >= n){
            q.push(input);
            q.pop();
        }
        else{ q.push(input); }
    }
    cout << q.top();
    return 0;
}