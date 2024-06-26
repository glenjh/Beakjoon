#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    
    int n, m, cnt = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        d.push_back(i);
    }

    for(int i = 0 ; i < m ; i++){
        int input; 
        cin >> input;
        
        while(true){    
            if(d.front() == input){
                d.pop_front();
                break;
            }
            else{
                for(int i = 0 ; i < d.size() ; i++){
                    if(d[i] == input){
                        if(i <= d.size() / 2){
                            d.push_back(d.front());
                            d.pop_front();
                            cnt++;
                        }else{
                            d.push_front(d.back());
                            d.pop_back();
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}