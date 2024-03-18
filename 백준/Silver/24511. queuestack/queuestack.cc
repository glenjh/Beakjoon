#include <iostream>
#include <deque>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    deque<int> d;
    int deter[100001];
    int n, m;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> deter[i];
    }

    for(int i = 0 ; i < n ; i++){
        int element;
        cin >> element;
        if(deter[i] == 0){
            d.push_back(element);
        }
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int input;
        cin >> input;
        d.push_front(input);
        cout << d.back() << ' ';
        d.pop_back();
    }
    
    cout << '\n';

    return 0;
}