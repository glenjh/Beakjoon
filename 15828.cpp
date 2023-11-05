#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;

    while (true){
        int input;
        cin >> input;

        if(input == -1){ break; }

        if(input != 0){
            if(q.size() < n){
                q.push(input);
            }
        }else{
            q.pop();
        }
    }
    
    if(q.empty()){
        cout << "empty" << '\n';
    }else{
        while(!q.empty()){
            cout << q.front() << ' ';
            q.pop();
        }
    }

    return 0;
}