#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ring_num, ring_size;
    cin >> ring_num;
    vector<int> v;
    for(int i=0 ; i<ring_num ; i++){
        cin>> ring_size;
        v.push_back(ring_size);
    }

    for(int i=1 ; i<v.size() ; i++){
        for(int j=v[i] ; j >= 1 ; j--){
            if(v[0]%j == 0 && v[i]%j == 0){
                cout << v[0]/j << "/" << v[i]/j << endl;
                break;
            }
        }
        continue;
    }
    return 0;
}