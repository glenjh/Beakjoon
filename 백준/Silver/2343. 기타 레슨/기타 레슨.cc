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

    long long n, m, answer = 0, l = 0, r = 0, mid;
    vector<long long> v;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        r += input;
        v.push_back(input);
    }

    l = v[v.size() - 1];

    while(l <= r){
        mid = (l + r) / 2;

        long long sum = 0, cnt = 1;
        for(int i = 0 ; i < n ; i++){
            if(v[i] > mid){
                cnt = m + 1;
                break;
            }

            if(sum + v[i] <= mid){
                sum += v[i];
            }
            else{
                sum = v[i];
                cnt += 1;
            }   
        }

        if(cnt <= m){
            answer = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}