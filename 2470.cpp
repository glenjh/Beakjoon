#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    vector<long long> v;
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        long long input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int l = 0, r = v.size() - 1; 
    long long lPoint, rPoint;
    long long diff = v[l] + v[r];

    while(r > l){
        long long mix = v[l] + v[r];

        if(abs(diff) >= abs(mix)){
            diff = mix;
            lPoint = l;
            rPoint = r;
            if(diff == 0){
                break;
            }
        }

        if(mix >= 0){
            r--;
        }else{
            l++;
        }
    }
    cout << v[lPoint] << ' ' << v[rPoint] << '\n';

    return 0;
}