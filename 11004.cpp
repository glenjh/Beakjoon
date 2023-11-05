#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v;
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin() , v.end());

    cout << v[k-1];
    return 0;
}