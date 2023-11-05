#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }else{
            return abs(a) > abs(b);
        }
    }
};


int main(){
    FastIO();

    priority_queue<int, vector<int>, cmp> pq;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        if(input != 0){
            pq.push(input);
        }else{
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}