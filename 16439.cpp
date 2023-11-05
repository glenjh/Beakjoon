#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[30][30];

    int n, m, cnt = 0;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < m ; i++){
        int M = 0;
        for(int j = 0 ; j < n ; j++){
            if(arr[j][i] >= M){
                M = arr[j][i];
            }
        }
        cout << M << ' ';
    }

    return 0;
}