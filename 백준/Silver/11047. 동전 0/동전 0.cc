#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    int k;
    int cnt = 0;

    cin >> n >> k;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[(n-1)-i];
    }

    for(int i=0;i<n;i++){
        if(k>=arr[i]){
            cnt+= k/arr[i];
            k = k%arr[i];
        }
    }
    cout << cnt;

    return 0;
}