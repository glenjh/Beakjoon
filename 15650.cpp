#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> list;
bool visited[8] = {false, };

void DFS(int idx , int cnt){
    if(cnt == m){
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == true){
                cout << list[i] << ' ';
            }
        }
        cout <<'\n';
    }
    else{
        for(int i=idx ; i<n ; i++){
            if(!visited[i]){
                visited[i] = true;
                DFS(i , cnt+1);
                visited[i] = false;
            }else{ continue; }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){ list.push_back(i); }

    DFS(0 ,0);
    return 0;
}