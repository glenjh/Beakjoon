#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,a,b,c = 0;
    long long cnt = 0;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a;
        v.push_back(a);
    }
    cin >> b >> c;
    for(auto it : v){
        it = it - b;
        cnt++;
        if(it <= 0){ continue; }
        else{
            if(it%c == 0){
                cnt += it/c;
            }else{
                int x = it/c;
                cnt+= x;
                it = it%c;
                cnt++;
            }
        }        
    }
    cout << cnt;
    return 0;
}