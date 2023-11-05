#include <iostream>

using namespace std;

bool checked[1001] = {false, };
int n, k, cnt = 0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 2 ; i <= n ; i++){
        if(checked[i] == false){
            for(int j = 1 ; i * j <= n ; j++){
                if(checked[i * j] == false){
                    checked[i * j] = true;
                    cnt++;
                }
                if(cnt == k){
                    cout << i * j;
                    break;
                }
            }
        }
    }
    
    return 0;
}