#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , m, a , b;
    unordered_map<int,int> sang;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a;
        sang[a] += 1;
    }

    cin >> m;
    for(int i=0 ; i<m ; i++){
        cin >> b;
        cout << sang[b] << " ";
    }
    return 0;
}