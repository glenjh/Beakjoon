#include <iostream>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int arr[250001];
    int n, x, answer = 0, cnt = 0;
    cin >> n >> x;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int pivot = 0, left = 0, right = x;
    for(int i = 0 ; i < x ; i++){
        pivot += arr[i];
    }
    
    if(pivot >= answer){
        cnt += 1;
        answer = pivot;
    }

    while(right < n){
        pivot -= arr[left];
        pivot += arr[right];
        left += 1;
        right += 1;

        if(pivot > answer){
            answer = pivot;
            cnt = 1;
        }else if(answer == pivot){
            cnt += 1;
        }
    }

    if(answer == 0){
        cout << "SAD" << '\n';
    }
    else{
        cout << answer << '\n';
        cout << cnt << '\n';
    }

    return 0;
}