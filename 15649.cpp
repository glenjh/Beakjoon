#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
vector<int> v;

int n, m;

bool visited[8] = {false, };

void DFS(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            cout << v[i]<< " ";
        }
        cout << '\n';
    }else{
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                visited[i] = true;
                v.push_back(list[i]);
                DFS(cnt + 1);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){ list.push_back(i); }
    DFS(0);
    return 0;
}