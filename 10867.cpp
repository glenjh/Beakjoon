#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        s.insert(input);
    }

    for(auto it : s){
        cout << it << " ";
    }
    cout << '\n';
}