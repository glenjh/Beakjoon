#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
int arr[100001];
int a[100001] = {0, };
int b[100001] = {0, };

int INC(){
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] <= arr[i+1]){
            a[i+1] = a[i] + 1;
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans, a[i]);
    }
    return ans;
}

int DEC(){
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] >= arr[i+1]){
            b[i+1] = b[i] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, b[i]);
    }
    return ans;
}

int main(){
    FastIO();

    for(int i = 0 ; i < 100001 ; i++){
        a[i] = 1;
        b[i] = 1;
    }

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int temp = INC();
    int temp2 = DEC();

    //cout << temp << ' ' << temp2 << '\n';

    int answer = max(temp, temp2);
    cout << answer << '\n';

    return 0;
}