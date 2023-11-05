#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> b;
    vector<int> j;

    for(int i = 0 ; i < 3 ; i++){
        int burger;
        cin >> burger;
        b.push_back(burger);
    }

    for(int i = 0 ; i <2 ; i++){
        int juice;
        cin >> juice;
        j.push_back(juice);
    }

    sort(b.begin() , b.end());
    sort(j.begin() , j.end());

    cout << b[0] + j[0] - 50;
}