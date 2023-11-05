#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rel[1024][1024];
int n;

int devide_and_conquer(int x, int y){
    vector<int> temp;
    for(int i = x ; i < x + 2 ; i++){
        for(int j = y ; j < y + 2 ; j++){
            temp.push_back(rel[i][j]);
        }
    }
    sort(temp.begin() , temp.end());
    return temp[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> rel[i][j];
        }
    }

    while(n > 1){
        for(int i = 0 ; i < n ; i+=2){
            for(int j = 0 ; j < n ; j+=2){
                rel[i/2][j/2] = devide_and_conquer(i, j);
            }
        }
        n /= 2;
    }
    cout << rel[0][0];
    return 0;
}