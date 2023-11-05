#include <iostream>
#include <vector>
using namespace std;

vector<int> list;

int selected[7];
int n, m;

void DFS(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << selected[i] << ' ';
        }
        cout << '\n';
    }else{
        for(int i = 0 ; i < n ; i++){
            selected[cnt] = list[i];
            DFS(cnt + 1);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){ list.push_back(i+1); }
    DFS(0);
    return 0;
}