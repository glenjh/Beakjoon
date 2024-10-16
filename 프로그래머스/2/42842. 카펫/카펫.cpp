#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    int w = 3, h = 3;
    
    while(true){
        if(w * h == total){
            if(((w - 2) * (h - 2)) == yellow){
                break;
            }
            else{
                h += 1;
                w = h;
            }
        }
        else if(w * h > total){
            h += 1;
            w = h;
        }
        else if(w * h < total){
            w += 1;
        }
    }
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}