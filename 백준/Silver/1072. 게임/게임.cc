#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<long long> v;
    long long x, y, answer;   
    cin >> x >> y;
    
    long long rate = ((double)(y * 100) / (double)x);
    long long l = 1, r = x; 
    long long newRate;

    while(l <= r){
        long long mid = (l + r) / 2;
        // cout << mid << '\n';
        newRate = ((double)((y + mid) * 100) / (double)(x + mid));

        // cout << rate << ' ' << newRate << '\n';

        if(rate == newRate){
            // cout << "----" << '\n';
            // break;
            l = mid + 1;
        }else if(rate < newRate){
            // cout << "====" << '\n';
            v.push_back(mid);
            r = mid - 1;
        }
    }
    if(v.size() == 0){
        answer = -1;
    }else{
        answer = v[v.size() - 1];
    }
    
    cout << answer << '\n';

    return 0;
}