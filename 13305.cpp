#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> roads;
    vector<long long> costs;

    long long answer;
    int n;
    cin >> n;

    for(int i = 0 ; i < n-1 ; i++){
        long long road;
        cin >> road;
        roads.push_back(road);
    }

    for(int i = 0 ; i < n ; i++){
        long long cost;
        cin >> cost;
        costs.push_back(cost);
    }

    long long currCost = costs[0]; 
    answer += roads[0] * currCost;

    for(int i = 1 ; i < n ; i++){
        if(currCost > costs[i]){
            currCost = costs[i];
            answer += currCost * roads[i];
        }else{
            answer += currCost * roads[i];
        }
    }

    cout << answer << '\n';

    return 0;
}