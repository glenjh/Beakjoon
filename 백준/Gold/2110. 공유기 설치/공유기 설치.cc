#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(int a, int b){
    return a < b;
}

int main() {
    FastIO();

    vector<int> v;
    int n, c;
    cin >> n >> c;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end(), comp);

    int start = 1, end = v[n - 1] - v[0];
    int ans = 0;

    // 설치되는 거리를 기준으로 이분탐색 진행
    while(start <= end){
        int mid = (start + end) / 2;
        
        int prevHouse = v[0];
        int cnt = 1;
        for(int i = 1 ; i < n ; i++){
            if(v[i] - prevHouse >= mid){
                cnt += 1;
                prevHouse = v[i];
            }
        }

        if(cnt >= c){
            ans = max(ans, mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}