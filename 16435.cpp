#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[1000] = {0, };
    int n, l;
    cin >> n >> l;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= l){
            l++;
        }
    }
    cout << l;
    return 0;
}