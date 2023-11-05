#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    vector<int> v;
    int n, ropes;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> ropes;
        v.push_back(ropes);
    }
    sort(v.begin() , v.end(), comp);

    int max = v[0];
    for(int i = 1 ; i <= v.size() ; i++){
        int curr = v[i-1] * i;
        if(curr > max){ max = curr; }
    }
    cout << max;
    return 0;
}