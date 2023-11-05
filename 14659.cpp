#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v, score;
    int n, height;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> height;
        v.push_back(height);
    }

    for(int i = 0 ; i < v.size() ; i++){
        int pivot = v[i], cnt = 0;
        for(int j = i+1 ; j < v.size() ; j++){
            if(pivot > v[j]){  
                cnt++;
            }else{
                break;
            }
        }
        score.push_back(cnt);
    }

    cout << *max_element(score.begin(), score.end());
    return 0;
}