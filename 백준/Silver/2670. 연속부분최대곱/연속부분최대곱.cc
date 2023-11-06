#include <iostream>
#include <cmath>
#define MAX 10001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

double dp[MAX];

int main() {
    FastIO();

    int n;
    double arr[MAX];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    double local = 1, MM = 0;
    for(int i = 0 ; i < n ; i++){
        local *= arr[i];
        if(local > MM){
            MM = local;
        }
        if(local < 1){
            local = 1;
        }
    }

    printf("%.3lf", MM);

    return 0;
}