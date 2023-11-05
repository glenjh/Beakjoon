#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a){
    int sum = 0;
    for(auto it : a){
        sum += it;
    }
    return sum;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << sum(arr);
    return 0;
}