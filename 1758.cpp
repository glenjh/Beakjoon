#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(long long a, long long b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> tips;
    long long n, sum = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int tip;
        cin >> tip;
        tips.push_back(tip);
    }

    sort(tips.begin(), tips.end(), comp);

    for(int i = 0 ; i < n ; i++){
        if(tips[i] - i < 0){
            sum += 0;
        }else{
            sum += tips[i] - i; 
        }
    }
    cout << sum;
}