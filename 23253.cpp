#include <iostream>
#include <stack>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int n, m;
    bool flag = true;
    cin >> n >> m;

    stack<int> s[m];

    for(int i = 0 ; i < m ; i++){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; j++){
            int input;
            cin >> input;
            if(!s[i].empty()){
                if(input > s[i].top()){
                    flag = false;
                }
            }
            s[i].push(input);
        }
    }

    if(flag){
        cout << "Yes" << '\n';
    }else{
        cout << "No" << '\n';
    }

    return 0;
}