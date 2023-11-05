#include <iostream>
#include <vector>
using namespace  std;

int n, m;
int selected[8];
vector<int> list;

void DFS(int idx , int cnt){
    if(cnt == m){
        for(int i=0 ; i<m ; i++){
            cout << selected[i] << ' ';
        }
        cout << '\n';
    }else{
        for(int i = idx ; i < n ; i++){
            selected[cnt] = list[i];
            DFS(i , cnt+1);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){ list.push_back(i); }

    DFS(0, 0);
    return 0;

}