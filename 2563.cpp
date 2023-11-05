#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[101][101] = {0, };

int main(){
    FastIO();

    int n, answer = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        for(int a = x ; a < x+10 ; a++){
            for(int b = y ; b < y+10 ; b++){
                arr[a][b] = 1;
            }
        }
    }

    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            if(arr[i][j] == 1){
                answer += 1;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}