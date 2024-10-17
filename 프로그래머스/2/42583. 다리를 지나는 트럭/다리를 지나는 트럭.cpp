#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    
    queue<int> bridge;
    int weigthOnBridge = 0;
    
    while(true){
        if(idx == truck_weights.size()){ 
            answer += bridge_length;
            break; 
        }
        
        if(bridge.size() == bridge_length){
            weigthOnBridge -= bridge.front();
            bridge.pop();
        }
        
        int currCar = truck_weights[idx];
        if(weigthOnBridge + currCar <= weight){
            bridge.push(currCar);
            weigthOnBridge += currCar;
            idx++;
        }
        else{
            bridge.push(0);
        }
        answer++;
    }
    
    return answer;
}