#include <iostream>
using namespace std;

int sums[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, num ,start, end;

    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        sums[i + 1] = sums[i] + num;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> start >> end;
        cout << sums[end] - sums[start - 1] << '\n';
    }
    return 0;
}