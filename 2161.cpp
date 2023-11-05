#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    queue<int> q;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        q.push(i);
    }

    while(q.size() != 1){
        cout << q.front() << ' ';
        q.pop();

        int temp = q.front();
        q.pop();

        q.push(temp);
    }
    cout << q.front();

    return 0;
}