#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , input;
    double sum = 0;
    vector<int> v;
    vector<int> sorted_v;
    map<int , int> m;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> input;
        sum+=input;
        v.push_back(input);
        sorted_v.push_back(input);
        if(m.find(input) == m.end()){ m.insert({input,1}); }
        else{ m[input] += 1; }
    }

    stable_sort(sorted_v.begin() , sorted_v.end());
    
    sum = sum/n;
    sum = round(sum * 10) / 10;

    int max = 0;
    for(auto it : m){
        if(it.second > max){
            max = it.second;
        }
    }

    vector<int> can;
    for(auto it2 : m){
        if(it2.second == max){
            can.push_back(it2.first);
        }
    }

    if(round(sum) == -0){
        cout << 0 << '\n';
    }else { cout << round(sum) << '\n'; }
    cout << sorted_v[n/2] << '\n';//중앙값
    if(can.size() == 1){ //최빈값
        cout << can[0] << '\n';
    }else{
        cout << can[1] <<'\n';
    }
    cout << sorted_v[n-1] - sorted_v[0];//범위
    return 0;
}