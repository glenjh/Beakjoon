#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(int a, int b){
    return a < b;
}

int main(){
    FastIO();

    vector<int> v;
    int n, l, answer = 1;
    cin >> n >> l;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    int temp = l - 1;

    for(int i = 0 ; i < v.size()-1 ; i++){
        if(v[i+1] - v[i] <= temp){
            temp -= v[i+1] - v[i];
        }else{
            answer += 1;
            temp = l - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}