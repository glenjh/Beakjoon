#include <string>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    ll m = 1, M = (n / times.size()) * times[times.size() - 1];
    
    while(m <= M){
        ll mid = (m + M) / 2;
        ll sum = 0;
        
        for(int i = 0 ; i <times.size() ; i++){
            sum += mid / (ll)times[i];
        }
        
        if(sum >= n){
            M = mid - 1;
            answer = mid;
        }
        else{
            m = mid + 1;
        }
    }
    
    
    return answer;
}