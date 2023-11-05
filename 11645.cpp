#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        set<string> s;
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            string input;
            cin >> input;
            s.insert(input);
        }
        cout << s.size() << '\n';
    }
}