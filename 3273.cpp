#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, input, rel;
    int cnt = 0;
    cin >> n;
    vector<int> v;
    vector<int> v2;
    for(int i=0;i<n;i++){
        cin >> input;
        v.push_back(input);
    }
    cin >> rel;
    sort(v.begin(),v.end());

    
    int start = 0;
    int end = n-1;

    while(start < end){
        if(v[start] + v[end] == rel){
            cnt++;
            end--;
        }else if(v[start] + v[end] < rel){
            start++;
        }else{
            end--;
        }
    }
    cout << cnt;
    return 0;
}