#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> q;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        q.push(i);
    }
    if(q.size() == 1){
        cout << q.front();
    }else{
        while(true){
            q.pop();
            q.push(q.front());
            q.pop();

            if(q.size() == 1){
                break;
            }
        }
        cout << q.front();
    }
    return 0;
}