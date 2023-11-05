#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    vector<pair<int,int>> v;
    for(int i=0 ; i< testcase ; i++){
        int height , weight;
        cin >> weight >> height;
        v.push_back(pair<int,int>(weight , height));
    }
    for(int i=0 ; i<testcase ; i++){
        int r = 1;
        for(int j=0 ; j<testcase ; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                r+=1;
            }
        }
        cout << r << ' ';
    }
    
    return 0;
}