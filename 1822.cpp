#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int na, nb, cnt = 0;
    set<int> a;
    set<int> b;
    vector<int> v;

    cin >> na >> nb;
    for(int i = 0 ; i < na ; i++){
        int input;
        cin >> input;
        a.insert(input);
    }

    for(int i = 0 ; i < nb ; i ++){
        int input;
        cin >> input;
        b.insert(input);
    }

    for(auto it : a){
        if(b.find(it) == b.end()){
            cnt++;
            v.push_back(it);
        }
    }

    if(v.size() == 0){
        cout << 0;
    }else{
        cout << cnt << '\n';
        for(auto it : v){
            cout << it << ' ';
        }
    }
    
    return 0;
}