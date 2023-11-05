#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, value, num;
    cin >> n;
    priority_queue<int> q;
    for(int i=0 ; i<n ; i++){
        cin >> num;
        for(int j=0 ; j<num ; j++){
            cin >> value;
            q.push(value);
        }
        if(num == 0){
            if(q.empty() == true){
                cout << -1 << '\n';
            }
            else{
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}