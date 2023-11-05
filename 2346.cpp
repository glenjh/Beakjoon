#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    deque<pair<int, int>> d;
    vector<int> v;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        d.push_back({i+1, input});
    }

    int next = d.front().second;
    v.push_back(d.front().first);
    d.pop_front();

    while(!d.empty()){

        if(next > 0){
            for(int i = 0 ; i < next-1 ; i++){
                d.push_back(d.front());
                d.pop_front();
            }
            v.push_back(d.front().first);
            next = d.front().second;
            d.pop_front();
        }
        else{
            for(int i = 0 ; i < abs(next) ; i++){
                d.push_front(d.back());
                d.pop_back();
            }
            v.push_back(d.front().first);
            next = d.front().second;
            d.pop_front();
        }
    }

    for(auto it : v){
        cout << it << ' ';
    }

    return 0;
}