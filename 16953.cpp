#include <iostream>

using namespace std;

long long a, b, rel = 10000000;

void DFS(long long curr, long long dep){
    if(curr > b){ return; }

    if(curr == b){ 
        rel = min(rel, dep);
        return;
    }

    DFS(2 * curr , dep+1);
    DFS( (10 * curr) + 1 , dep+1);
}

int main(){
    cin >> a >> b;

    DFS(a, 1);
    if(rel == 10000000){ cout << -1; }
    else{ cout << rel; }
    return 0;
}