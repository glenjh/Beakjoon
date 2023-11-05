#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int arr[6];
int k;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int idx, int cnt){
    if(cnt == 6){
        for(int i = 0 ; i < 6 ; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx ; i < v.size() ; i++){
        arr[cnt] = v[i];
        DFS(i+1, cnt+1);
    }
}

int main(){
    FastIO();

    while(true){
        v.clear();
        cin >> k;
        if(k == 0){ break; }

        for(int i = 0; i < k ; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }

        DFS(0, 0);
        cout << '\n';
    }

    return 0;
}