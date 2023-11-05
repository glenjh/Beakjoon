#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    vector<int> v;
    int n, m, sum = 0, cnt = 0;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        vector<int> temp;
        int p, l;
        cin >> p >> l;

        for(int j = 0 ; j < p ; j++){
            int input;
            cin >> input;
            temp.push_back(input);
        }

        if(p < l){
            v.push_back(1);
        }else{
            sort(temp.begin(), temp.end(), comp);
            v.push_back(temp[l - 1]);
        }
    }
    sort(v.begin(), v.end());

    for(auto it : v){
        sum += it;
        if(sum <= m){
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}