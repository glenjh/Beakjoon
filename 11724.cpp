#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];

int find(int a){
    if(a == arr[a]){ return a; }
    else{ 
        return find(arr[a]);
    }
}

void uni(int a , int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        arr[pb] = arr[pa];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0 ; i<1001 ; i++){
        arr[i] = i;
    }

    vector<int> v;
    int n , m , cnt = 0;
    int parent , child;
    cin >> n >> m;

    for(int i=0 ; i<m ; i++){
        cin >> parent >> child;
        uni(parent , child);
    }
    
    for(int i=1 ; i<= n ; i++){
        int cmp = find(i);
        if(find(v.begin() , v.end() , cmp) == v.end()){
            v.push_back(cmp);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}