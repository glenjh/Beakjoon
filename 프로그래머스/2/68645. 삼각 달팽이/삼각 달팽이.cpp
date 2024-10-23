#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    
    int limit = 0;
    for(int i = 1 ; i <= n ; i++){
        limit += i;
    }
    
    int val = 1;
    int state = 0;
    int left = 1, right = 0, up = 1, down = n;
    
    while(val <= limit){
        if(state == 0){
            for(int i = up ; i <= down ; i++){
                arr[i][left] = val;
                val++;
            }
            state++;
            up++;
            left++;
        }
        
        else if(state == 1){
            for(int i = left ; i <= down - right ; i++){
                arr[down][i] = val;
                val++;
            }
            state++;
            down--;
        }
        
        else if(state == 2){
            for(int i = down ; i >= up ; i--){
                arr[i][i - right] = val;
                val++;
            }
            state = 0;
            right++;
            up++;
        }
    }
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}