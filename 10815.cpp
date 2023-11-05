#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    int n , n_cards , m , m_cards;
    set<int> s;
    map<int,int> s2;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> n_cards;
        s.insert(n_cards);
    }

    cin >> m;
    for(int i=0 ; i<m ; i++){
        cin >> m_cards;
        s2.insert(pair<int,int>(i,m_cards));
    }
    for(int i=0 ; i<m ; i++){
        if(s.find(s2[i]) == s.end()){
            cout << 0 << " ";
        }else{ cout << 1 << " "; }
    }
    
    return 0;
}