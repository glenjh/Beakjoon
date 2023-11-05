#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int num;
    int arr[6] = {1, 1, 2, 2, 2, 8};

    for(int i=0 ; i<6 ; i++){
        cin >> num;
        v.push_back(num);
    }

    for(int i=0 ; i<6 ; i++){
        cout << arr[i]-v[i] << ' ';  
        
    }
    return 0;
}