#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <climits>
#include <vector>
#include <functional>
#define ll long long int

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;

    for(int testcase = 0 ; testcase < t ; testcase++){
        priority_queue<ll, vector<ll>, greater<ll>> minToMax; // 오름차순
        priority_queue<ll, vector<ll>, less<ll>> maxToMin;    // 내림차순
        ll k;
        map<ll, ll> m;
        cin >> k;

        for(ll i = 0 ; i < k ; i++){
            string command;
            cin >> command;

            if(command == "I"){
                ll input;
                cin >> input;
                minToMax.push(input);
                maxToMin.push(input);
                m[input]++;
            }
            else if(command == "D"){
                int delCommand;
                cin >> delCommand;

                if(minToMax.empty() && maxToMin.empty()){ continue; }
                else{
                    if(delCommand == 1){
                        if(!maxToMin.empty()){
                            m[maxToMin.top()]--;
                            maxToMin.pop();
                        }
                    }
                    else if(delCommand == -1){
                        if(!minToMax.empty()){
                            m[minToMax.top()]--;
                            minToMax.pop();
                        }
                    }

                    while(!minToMax.empty() && m[minToMax.top()] == 0){
                        minToMax.pop();
                    }

                    while(!maxToMin.empty() && m[maxToMin.top()] == 0){
                        maxToMin.pop();
                    }
                }
            }
        }

        if(minToMax.empty() && maxToMin.empty()){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << maxToMin.top() << ' ' << minToMax.top() << '\n';
        }
    }
    return 0;
}