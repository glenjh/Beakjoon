#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int n , k , score;
    vector<int> v , v2;
    set<int> s;

    cin >> n >> k;
    for(int i=0 ; i<n ; i++){
        cin >> score;
        v.push_back(score);
    }

    sort(v.begin() , v.end() , greater<int>());
    cout << v[k-1];
    return 0;
}