#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, k, answer = -100000001;
    int arr[100001];
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int start = 0, end = start + k - 1, sum = 0, cnt = 0;
    for(int i = start ; i <= end ; i++){
        sum += arr[i];
    }
    // cout << sum << '\n';
    // cout << '\n';
    answer = max(answer, sum);
    end += 1;

    if(n != k){
        while(end < n){
            // end += 1;
            sum = sum - arr[start] + arr[end];
            // cout << start << ' ' << end << '\n';
            // cout << sum << '\n';
            answer = max(answer, sum);
            // cout << "ans: " << answer << '\n';
            start += 1;
            end += 1;
        }   
    }
    cout << answer << '\n';

    return 0;
}