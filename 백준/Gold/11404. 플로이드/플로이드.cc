#include <iostream>
#define MAX 101
#define INF 987654321

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int arr[MAX][MAX];
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            if(i == j){
                arr[i][j] = 0;
            }else{
                arr[i][j] = INF;
            }
        }
    }

    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(arr[a][b] != 0){
            arr[a][b] = min(arr[a][b], c);
        }
    }

    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(arr[i][j] == 0 || arr[i][j] == INF){
                cout << 0 << ' ';
            }else{
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}