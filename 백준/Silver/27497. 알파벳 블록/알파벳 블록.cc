#include <iostream>
#include <stack>
#include <deque>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    stack<int> s;
    deque<string> d;
    int n;
    string answer = "";
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string command, input;
        cin >> command;

        if(command == "1"){
            cin >> input;
            s.push(1);
            d.push_back(input);
        }
        else if(command == "2"){
            cin >> input;
            s.push(-1);
            d.push_front(input);
        }
        else if(command == "3"){
            if(!s.empty()){
                if(s.top() == -1){
                    d.pop_front();
                }else{
                    d.pop_back();
                }

                s.pop();
            }
        }
    }

    for(int i = 0 ; i < d.size() ; i++){
        answer += d[i];
    }

    if(answer == ""){
        cout << "0" << '\n';
    }else{
        cout << answer << '\n';
    }

    return 0;
}