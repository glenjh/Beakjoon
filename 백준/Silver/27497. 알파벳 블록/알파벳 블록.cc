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

    stack<pair<string, string>> s;
    deque<pair<string, string>> d;
    int n, cnt = 0;
    string answer = "";
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string command, input;
        cin >> command;

        if(command == "1"){
            cin >> input;
            s.push({input, "back"});
            d.push_back({input, "back"});
        }
        else if(command == "2"){
            cin >> input;
            s.push({input, "front"});
            d.push_front({input, "front"});
        }
        else if(command == "3"){
            if(!s.empty()){
                if(s.top().second == "front"){
                    d.pop_front();
                }else{
                    d.pop_back();
                }

                s.pop();
            }
        }
    }

    for(int i = 0 ; i < d.size() ; i++){
        answer += d[i].first;
    }

    if(answer == ""){
        cout << "0" << '\n';
    }else{
        cout << answer << '\n';
    }

    return 0;
}