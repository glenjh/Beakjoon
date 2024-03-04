#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, len = nums.size() / 2;
    set<int> s;
    for(auto it : nums){
        s.insert(it);
    }
    
    if(s.size() <= len){
        answer = s.size();
    }
    else{
        answer = len;
    }
    
    return answer;
}