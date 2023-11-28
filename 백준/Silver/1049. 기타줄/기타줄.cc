#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, m, rel;
    vector<int> package, single;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        package.push_back(a);
        single.push_back(b);
    }

    sort(package.begin(), package.end());
    sort(single.begin(), single.end());

    int justSingle = single[0] * n;
    int bundle = 0, cnt = 0;
    while(cnt < n){
        bundle += package[0];
        cnt += 6;
    }

    int mix = 0, mixCnt = 0;
    while(mixCnt + 6 < n){
        mix += package[0];
        mixCnt += 6;
    }
    mix += (n - mixCnt) * single[0];

    rel = min(min(justSingle, bundle), mix);
    cout << rel << '\n';

    return 0;
}