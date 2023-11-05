#include <iostream>
#include <queue>
#include <functional>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;

    for(int testcase = 0 ; testcase < t ; testcase++){
        priority_queue<long long, vector<long long>, greater<long long>> min_to_max;
        priority_queue<long long, vector<long long>, less<long long>> max_to_min;
        int k, total_size = 0;
        cin >> k;

        for(int i = 0 ; i < k ; i++){
            string command;
            cin >> command;

            if(command == "I"){
                long long input;
                cin >> input;
                min_to_max.push(input);
                max_to_min.push(input);
                total_size++;
            }
            else if(command == "D"){
                int input;
                cin >> input;

                if(total_size == 1){
                    max_to_min.pop();
                    min_to_max.pop();
                    total_size--;
                }

                if(total_size == 0){
                    continue;
                }
                else{
                    if(input == 1){
                        max_to_min.pop();
                        total_size--;
                    }
                    else if(input == -1){
                        min_to_max.pop();
                        total_size--;
                    }
                }
            }
        }
        if(total_size <= 0){
            cout << "EMPTY" << '\n';
        }else{
            cout << max_to_min.top() << " " << min_to_max.top() << '\n';
        }
        while(!min_to_max.empty()){
            min_to_max.pop();
        }
        while(!max_to_min.empty()){
            max_to_min.pop();
        }
    }
    return 0;
}