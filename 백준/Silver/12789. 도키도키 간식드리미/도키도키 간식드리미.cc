#include <iostream>
#include <stack>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    stack<int> s;
    int n;
    cin >> n;
    int arr[MAX];
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    int curr = 1;
    int idx = 1;
    for(int i = 1 ; i <= n ; i++){
        if(s.empty() && idx <= n){
            s.push(arr[idx]);
            idx++;
        }

        while(s.top() != curr && idx <= n){
            s.push(arr[idx]);
            idx++;
        }

        if(!s.empty() && s.top() == curr){
            s.pop();
            curr++;
        }else{
            cout << "Sad" << '\n';
            return 0;
        }
    }
    cout << "Nice" << '\n';

    return 0;
}