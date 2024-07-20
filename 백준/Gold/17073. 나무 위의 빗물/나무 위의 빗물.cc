#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v[500001];

int main() {
    FastIO();

    int n, w;
    double ans, leafCnt = 0;
    cin >> n >> w;
    for(int i = 0 ; i < n - 1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        if(v[i].size() == 1 && i != 1){
            leafCnt += 1;
        }
    }

    if(leafCnt == 0){
        leafCnt = 1;
    }
    
    ans = w / leafCnt;
    cout.precision(6);
    cout << fixed << ans << '\n';

    return 0;
}