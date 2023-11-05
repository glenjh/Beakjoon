#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, flag, a, t, score = 0;
    stack<pair<int,int>> s;

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> flag;
        if(flag != 0){
            cin >> a >> t;
            if(t-1 == 0){ score += a; }
            else{ s.push(pair<int,int>(a , t-1)); }
        }
        else{ 
            if(!s.empty()){ 
                s.top().second--;
                if(s.top().second == 0){
                    score += s.top().first;
                    s.pop();
                }  
            }
        }
    }

    cout << score;
    return 0;
}