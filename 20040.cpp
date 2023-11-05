#include <iostream>
using namespace std;
int p[5000000];

int find(int a){
    if(p[a] == a){ return a; }
    else{ 
        p[a] = find(p[a]);
        return p[a];
    }
}

bool uni(int a, int b){
    int parent_a = find(a);
    int parent_b = find(b);
    if(parent_a != parent_b){
        p[parent_b] = parent_a; 
        return false;
    }else{ return true; }
}

int main(){
    bool circle = false;
    int n,m, x,y, circle_point;
    cin >> n >> m;
    
    for(int i=0 ; i<n ; i++){
        p[i] = i;
    }
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        if(uni(x,y) == true){
            circle_point = i+1;
            circle = true;
            break;
        }
    }
    if(circle == true){
        cout << circle_point;
    }else{
        cout << 0;
    }
    return 0;
}