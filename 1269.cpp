#include<iostream>
#include<set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a_num, b_num,x,y;
    set<int> a;
    set<int> b;
    // vector<int>a_b;
    // vector<int>b_a;
    int cnt = 0;
    cin >> a_num >> b_num;
    for(int i=0 ; i<a_num ; i++){
        cin >> x;
        a.insert(x);
    }
    for(int i=0 ; i<b_num ; i++){
        cin >> y;
        b.insert(y);
    }

    for(auto i : a){
        if(b.find(i)  == b.end()){
            //a_b.push_back(i);
            cnt++;
        }
    }

    for(auto i : b){
        if(a.find(i) == a.end()){
            //b_a.push_back(i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
