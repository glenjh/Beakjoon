#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    int n , m, cnt=0;
    set<string> s;
    set<string> sub_s;
    cin >> n >> m;
    string words , sub_words;
    for(int i=0 ; i< n ; i++){
        cin >> words;
        s.insert(words);
    }

    for(int i=0 ; i<m ; i++){
        cin >> sub_words;
        if(s.find(sub_words) != s.end()){
            cnt++;
            continue;
        }
    }
    cout << cnt;
    return 0;
}