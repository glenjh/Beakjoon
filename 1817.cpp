#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int n, m, boxCount = 0, currBoxWeight = 0;
    cin >> n >> m;

    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        int weight;
        cin >> weight;
        q.push(weight);
    }

    int curr = q.front();
    boxCount += 1;
    q.pop();

    while (!q.empty()){
       int nextBook = q.front();
       if((curr + nextBook) > m){
        boxCount += 1;
        curr = nextBook;
        q.pop();
       }else{
        curr += nextBook;
        q.pop();
       }
    }
    

    cout << boxCount << '\n';

    return 0;
}