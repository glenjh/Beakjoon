#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int arr[100001];
    int g;
    vector<int> v;
    for(int i = 0 ; i < 100001 ; i++){
        arr[i] = i * i;
    }

    cin >> g;
    int past = 1, curr = 1;

    while(curr <= 100000){
        int sub = arr[curr] - arr[past];
        if(sub == g){
            v.push_back(curr);
            past += 1;
        }
        else{
            if(sub > g){
                past += 1;
            }
            else if(sub < g){
                curr += 1;
            }
        }
    }

    if(v.size() == 0){
        cout << -1 << '\n';
    }
    else{
        for(auto it : v){
            cout << it << '\n';
        }
    }

    return 0;
}