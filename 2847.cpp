#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, score, cnt = 0;
    vector<int> v;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> score;
        v.push_back(score);
    }

    for(int i = v.size()-1 ; i > 0 ; i--){
        if(v[i] <= v[i-1]){
            int diff = v[i-1] - v[i] + 1;
            v[i-1] -= diff;
            cnt += diff;
        }
    }
    
    cout << cnt;
    return 0;
}