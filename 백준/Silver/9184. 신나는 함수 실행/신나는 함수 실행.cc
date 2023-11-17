#include <iostream>
#define MAX 21

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int a, b, c;
int dp[MAX][MAX][MAX];

int W(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if(a > 20 || b > 20 || c > 20){
        return W(20, 20, 20);
    }

    if(dp[a][b][c] == -1){
        if(a < b && b < c){
            dp[a][b][c] =  W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
        }
        else{
            dp[a][b][c] =  W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
        }
    }

    return dp[a][b][c];
}

int main() {
    FastIO();

    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            for(int k = 0 ; k < MAX ; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){ break; }

        int rel = W(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << rel << '\n';

    }

    return 0;
}