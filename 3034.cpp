#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, w, h, size;
    cin >> n >> w >> h;
    for(int i=0 ; i<n ; i++){
        cin >> size;
        if(size <= w || size <= h || size <= sqrt((w*w)+(h*h))){
            cout << "DA" << endl;
        }else{
            cout << "NE" << endl;
        }
    }
    return 0;
}