#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long int> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, n;
    long long int big = 0, answer = 0;
    cin >> k >> n;

    for(int i = 0 ; i < k ; i++){
        long long int input;
        cin >> input;
        big = max(input, big);
        arr.push_back(input);
    }

    long long int start = 1, end = big;
    while(start <= end){

        long long int mid = (start + end) / 2;
        long long int cnt = 0;

        for(int i = 0 ; i < k ; i++){
            cnt += (arr[i] / mid);
        }

        if(cnt >= n){
            start = mid + 1;
            answer = max(mid, answer);
        }
        else if(cnt < n){
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}