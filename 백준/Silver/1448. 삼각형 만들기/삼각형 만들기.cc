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
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), comp);

    int pivot = v.size() - 1;
    bool flag = false;

    while (pivot >= 2){
        if(v[pivot - 1] + v[pivot - 2] > v[pivot]){
            flag = true;
            break;
        }
        pivot--;
    }

    if(!flag){
        cout << -1 << '\n';
    }else{
        cout << v[pivot] + v[pivot - 1] + v[pivot - 2] << '\n';
    }
    

    return 0;
}