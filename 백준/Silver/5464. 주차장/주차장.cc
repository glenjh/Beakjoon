#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<pair<bool, int>> isParked(101, {false, 0}); 
    queue<int> waiting;
    int n, m, cost[101], cars[2001], cnt = 0, answer = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        cin >> cost[i];
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> cars[i];
    }

    for(int i = 0 ; i < 2 * m ; i++){
        int input;
        cin >> input;

        if(input > 0){
            cnt++;
            for(int j = 0 ; j < n ; j++){
                if(!isParked[j].first){
                    isParked[j].first = true; 
                    isParked[j].second = input;
                    break;
                }
            }
            if(cnt > n){
                waiting.push(input);
            }
        }
        else if(input < 0){
            input *= -1;
            
            for(int j = 0 ; j < n ; j++){
                if(isParked[j].second == input){
                    answer += cars[isParked[j].second] * cost[j + 1];
                    cnt--;

                    if (!waiting.empty()){
                        isParked[j].second = waiting.front();
                        waiting.pop();
                    }
                    else{
                        isParked[j].first = false;
                        isParked[j].second = 0;
                    }

                    break;
                }
            }
        }
    }
    cout << answer << '\n';

    return 0;
}