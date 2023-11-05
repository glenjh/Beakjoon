#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset<int> s;
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int a_element;
        cin >> a_element;
        s.insert(a_element);
    }

    for(int i = 0 ; i < m ; i++){
        int b_element;
        cin >> b_element;
        s.insert(b_element);
    }

    for(auto it : s){
        cout << it << " ";
    }
    return 0;
}