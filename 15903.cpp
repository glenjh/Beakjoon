#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long sum = 0;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for(int i = 0 ; i < n ; i++){
        int cards;
        cin >> cards;
        q.push(cards);
    }

    
    for(int i = 0 ; i < m ; i++){
        long long temp = 0;
        temp += q.top();
        q.pop();

        temp += q.top();
        q.pop();
        
        q.push(temp);
        q.push(temp);
    }

    while(!q.empty()){
        sum += q.top();
        q.pop();
    }

    cout << sum;
    return 0;
}