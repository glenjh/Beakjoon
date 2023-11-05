#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<long long, vector<long long>, greater<long long>> q;

    int n;
    long long sum = 0;

    cin >> n;


    for(int i = 0 ; i < n ; i++){
        long long card;
        cin >> card;
        q.push(card);
    }

    if(n == 1){
        cout << 0;
        return 0;
    }

    while (true){
        long long temp = 0;

        for(int i = 0 ; i < 2 ; i++){
            temp += q.top();
            q.pop();
        }
        sum += temp;

        if(q.empty()){ break; }
        q.push(temp);
    }

    cout << sum;
    return 0;
}