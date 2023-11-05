#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, w, l, truck_weight;
    cin >> n >> w >> l;
    queue<int> road;
    vector<int> cars;
    int max_on_road=w , sum=0, cnt=0;

    for(int i=0 ; i<n ; i++){
        cin >> truck_weight;
        cars.push_back(truck_weight);
    }

    for(int i=0 ; i<cars.size() ; i++){
        while(true){
            if(road.size() == max_on_road){
                sum -= road.front();
                road.pop();
            }

            if(sum + cars[i] <= l){ goto can_pass; }
            else{
                road.push(0);
                cnt++;
            }
        }
        can_pass:
        road.push(cars[i]);
        sum += cars[i];
        cnt++;
    }

    cout << cnt+w; //아직 하나는 못건넘 진입?만 한 상태
    return 0;
}