#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, cnt;
    string clothes, type;
    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        cnt = 1;
        map<string, int> m;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> clothes >> type;
            m[type]++;
        }

        for(auto it : m){
            cnt *= it.second + 1;
        }
        cout << cnt -1 << '\n';
    }
    return 0;
}