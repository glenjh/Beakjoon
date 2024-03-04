#include <iostream>
#include<unordered_set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    unordered_set<string> s;
    bool flag = false;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string a, b;
        cin >> a >> b;
        if (a == "ChongChong" || b == "ChongChong"){
            flag = true;
            s.insert(a);
            s.insert(b);
        }

        if(flag){
            if(s.find(a) != s.end()){
                s.insert(b);
            }

            if(s.find(b) != s.end()){
                s.insert(a);
            }
        }
    }

    cout << s.size() << '\n';

    return 0;
}