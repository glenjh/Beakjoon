#include <iostream>
#define ll long long int 

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int arr[10001];
    int n, m, answer = 0;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    ll start = 0, end = 0, sum = arr[start];
    while(end < n){
        if(start != end){
            sum += arr[end];
        }

        if(sum == m){
            answer += 1;
            start += 1;
            end = start;
            sum = arr[start];
        }
        else{
            if(sum < m){
                end += 1;
            }
            else if(sum > m){
                start += 1;
                end = start;
                sum = arr[start];
            }
        }
    }

    cout << answer << '\n';

    return 0;
}