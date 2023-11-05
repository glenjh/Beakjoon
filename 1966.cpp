#include <iostream>
#include <queue>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i=0 ; i<t ; i++){
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int n, m , p;
        int num = 0;
        cin >> n >> m;
        for(int j=0; j<n ; j++){
            cin >> p;
            q.push(pair<int,int>(j,p));
            pq.push(p);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++num;
                if (index == m) {
                    cout << num << endl;
                    break;
                }
            }
            else q.push(pair<int,int>(index , value));
        }
    }
}