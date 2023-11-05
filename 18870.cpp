#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;
    set<int> s;
    vector<int> rel;
    vector<int> v;
    for(int i=0 ; i< n; i++){
        cin >> x;
        rel.push_back(x);
        s.insert(x);
    }
   
    for(auto it : s){
        v.push_back(it);
    }

    for(auto it2 : rel){
        cout << lower_bound(v.begin() , v.end() , it2) - v.begin() << " ";
    }
    return 0;
}