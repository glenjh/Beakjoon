#include <vector>
#include <iostream>
#include <vector>

using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    vector<pair<int,int>> v;
    int k , dir , len  , w = 0 , h = 0 , sw , sh;
    cin >> k;

    for(int i=0 ; i<6 ; i++){
        cin >> dir >> len;
        v.push_back(pair<int,int>(dir , len));
    }

    for(int i=0 ; i<6 ; i++){
        if(i%2 == 0){
            if(v[i].second > w){ w = v[i].second; }
        }else{
            if(v[i].second > h){ h = v[i].second; }
        }
    }
    
    for(int i=0 ; i<6 ; i++){
        if(i%2 == 0){
            if( (v[(i+5) % 6].second + v[(i+1) % 6].second) == h){ sw = v[i].second; }
        }else{
            if( (v[(i+5) % 6].second + v[(i+1) % 6].second) == w){ sh = v[i].second; }
        }
    }

    cout << (w * h - sw * sh) * k  ;
    return 0;
}