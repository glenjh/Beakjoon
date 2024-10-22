#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];
pair<int, int> dir[2] = { {1, -1}, {1, 1} };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 0 ; i < triangle.size() ; i++){
        for(int j = 0 ; j < triangle[i].size() ; j++){
            arr[i][j] = triangle[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for(int i = 1 ; i < triangle.size() ; i++){
        for(int j = 0 ; j < triangle[i].size() ; j++){
            if(j == 0){
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], 
                                dp[i - 1][j] + arr[i][j]);
            }
        }
    }
    
    for(int i = 0 ; i < triangle.size() ; i++){
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    
    return answer;
}