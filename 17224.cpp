#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, k, answer = 0;
    vector<int> v;

    cin >> n >> l >> k;
    for(int i = 0 ; i < n ; i++){
        int easy, hard;
        cin >> easy >> hard;
        int score = 0;
        if(l >= hard){
            score = 140;
        }else if(l >= easy){
            score = 100;
        }
        v.push_back(score);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 0; i < k ; i++){
        answer += v[i];
    }

    cout << answer << '\n';

    return 0;
}