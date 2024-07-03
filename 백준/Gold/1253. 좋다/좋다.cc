#include <iostream>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[2000];

int main() {
    FastIO();

    int n, answer = 0, target;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for(int i = 0 ; i < n ; i++){
        int l = 0, r = n - 1;
        while(l < r){
            target = arr[i];
            if(arr[l] + arr[r] == target){
                if(l != i && r != i){
                    answer += 1;
                    break;
                }
                else if(l == i){
                    l++;
                }
                else if(r == i){
                    r--;
                }
            }
            else if (arr[l] + arr[r] > target){
                r -= 1;
            }
            else{
                l += 1;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}