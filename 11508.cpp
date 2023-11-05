#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    long long n, answer = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i ++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    if(n < 3){
        for(int i = 0 ; i < n ; i++){
            answer += v[i];
        }
    }
    else{
        for(int i = 0 ; i < v.size() ; i++){
            if((i+1) % 3 == 0){
                continue;
            }
            answer += v[i];
        }
    }
    
    cout << answer << '\n';

    return 0;
}