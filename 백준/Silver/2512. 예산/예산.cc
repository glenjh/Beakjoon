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

    int n, sum = 0, m, answer;  
    vector<int> v;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
        sum += input;
    }
    sort(v.begin(), v.end());

    cin >> m;
    if(sum <= m){
        answer = v[v.size() - 1];
    }
    else{
        int l = 1, r = v[n - 1], mid, temp;
        while(l <= r){

            temp = 0;
            mid = (l + r) / 2;

            for(auto it : v){
                if(it > mid){
                    temp += mid;
                }else{
                    temp += it;
                }
            }

            if(temp > m){
                r = mid - 1;
            }else if(temp <= m){
                answer = mid;
                l = mid + 1;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}