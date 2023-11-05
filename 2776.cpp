#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int testcase = 0 ; testcase < t; testcase++){
        set<int> note;
        vector<int> v;
        int n, m;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            int input;
            cin >> input;
            note.insert(input);
        }

        cin >> m;

        for(int i = 0 ; i < m ; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }

        for(auto it : v){
            if(note.find(it) == note.end()){
                cout << 0 << '\n';
            }else{
                cout << 1 << '\n';
            }
        }

    }

    return 0;
}