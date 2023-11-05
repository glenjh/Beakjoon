#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long answer = 1;
    int n, max = 0;
    vector<int> v;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0 ; i < n ; i++){
        int day = v[i] + (i + 1);
        if(day > max){
            max = day;
        }
    }

    cout << answer + max << '\n';

    return 0;
}