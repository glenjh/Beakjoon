#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    priority_queue < int, vector<int>, greater<int> > pq;
    vector<pair<int, int>> v;

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);

    for(int i = 1 ; i < n ; i++){
        if(pq.top() <= v[i].first){
            pq.pop();
        }
        pq.push(v[i].second);
    }

    cout << pq.size() << '\n';
    
    return 0;
}