#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int nge[1000001];

int main(){
    FastIO();

    for(int i = 0 ; i < 1000001 ; i++){
        nge[i] = -1;
    }
  
    int n;
    cin >> n;
    stack<int> s;
    vector<int> v;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0 ; i < n ; i++){
        while(!s.empty() && v[s.top()] < v[i]){
            nge[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0 ; i < n ; i++){
        cout << nge[i] << ' ';
    }

    return 0;
}