#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> j;
    vector<int> bags;
    priority_queue<int> pq;
    
    int n, k;
    long long sum = 0;
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        int m, v;
        cin >> m >> v;
        j.push_back({m, v});
    }

    for(int i = 0 ; i < k ; i++){
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(j.begin() , j.end());
    sort(bags.begin() , bags.end());

    int pivot = 0;
    for(int i = 0 ; i < k ; i++){
        while(bags[i] >= j[pivot].first && pivot < n){
            pq.push(j[pivot].second);
            pivot++;
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }   
    }
    

    cout << sum;
}