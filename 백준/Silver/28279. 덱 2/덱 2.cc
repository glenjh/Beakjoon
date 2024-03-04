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
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int command, x;
        cin >> command;

        switch(command){
            case 1:
                cin >> x;
                d.push_front(x);
                break;
            case 2:
                cin >> x;
                d.push_back(x);
                break;
            case 3:
                if(d.empty()){
                    cout << -1 << '\n';
                }
                else{
                    cout << d.front() << '\n';
                    d.pop_front();
                }
                break;
            case 4:
                if (d.empty()){
                    cout << -1 << '\n';
                }
                else{
                    cout << d.back() << '\n';
                    d.pop_back();
                }
                break;
            case 5:
                cout << d.size() << '\n';
                break;
            case 6:
                if(d.empty()){
                    cout << 1 << '\n';
                }else{
                    cout << 0 << '\n';
                }
                break;
            case 7:
                if (d.empty()){
                    cout << -1 << '\n';
                }
                else{
                    cout << d.front() << '\n';
                }
                break;
            case 8:
                if (d.empty()){
                    cout << -1 << '\n';
                }
                else{
                    cout << d.back() << '\n';
                }
                break;
        }
    }

    return 0;
}