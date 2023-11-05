#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    cin >> k;
    k = n/k;

    for(auto it = v.begin() ; it != v.end() ; ){
        sort(it, it + k);
        it += k;
    }

    for(auto it : v){ cout << it << ' '; }
    return 0;
}