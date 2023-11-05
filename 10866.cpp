#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque<int> d;
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        string order;
        cin >> order;
        if(order == "push_front"){
            int a;
            cin >> a;
            d.push_front(a);
        }else if(order == "push_back"){
            int b;
            cin >> b;
            d.push_back(b);
        }else if(order == "pop_front"){
            if(d.empty() == true){ cout << -1 << '\n'; }
            else{
                cout << d.front() << '\n';
                d.pop_front();
            }
        }else if(order == "pop_back"){
            if(d.empty() == true){
                cout << -1 << '\n';
            }else{
                cout << d.back() << '\n';
                d.pop_back();
            }
        }else if(order == "size"){
            cout << d.size() << '\n';
        }else if(order == "empty"){
            if(d.empty() == true){
                cout << 1 << '\n';
            }else{
                cout <<0 << '\n';
            }
        }else if(order == "front"){
            if(d.empty() == true){
                cout << -1 << '\n';
            }else{
                cout << d.front() << '\n';
            }
        }else if(order == "back"){
            if(d.empty() == true){
                cout << -1 << '\n';
            }else{
                cout << d.back() << '\n';
            }
        }
    }
    
    return 0;
}