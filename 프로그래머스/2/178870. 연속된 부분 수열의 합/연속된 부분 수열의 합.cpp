#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer, v;
    int start, end, L = sequence.size();
    
    v.push_back(0);
    int sum = 0;
    for(int i = 0 ; i < sequence.size() ; i++){
        sum += sequence[i];
        v.push_back(sum);
    }
    
    int l = 0, r = 0;
    while(l <= r && r <= sequence.size()){
        if(v[r] - v[l] < k){
            r++;
        }
        else if(v[r] - v[l] > k){
            l++;
        }
        else if(v[r] - v[l] == k){
            if(L > r - l - 1){
                L = r - l - 1;
                start = l;
                end = r - 1;
            }
            else if(L == l - r - 1){
                if(start > l){
                    start = l;
                    end - r - 1;
                }
            }
            r++;
        }
    }
    
    answer.push_back(start);
    answer.push_back(end);
    
    return answer;
}