#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    vector<int> v;
    int n, idx, answer = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    if (n <= 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    while(true){
        int M  = 0;

        for(int i = 1 ; i < n ; i++){
            if(v[i] > M){
                M = v[i];
                idx = i;
            }
        }

        if(v[0] > v[idx]){ break; }
        v[0]++;
        v[idx]--;
        answer++;
    }

    cout << answer << '\n';

    return 0;
}