#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> rel;
int arr[100][100];
int width;
int m,n;

bool visited[100][100] = {false,};
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0}; //y축 +-1, x축 +-1

void DFS(int x, int y){
    if(visited[x][y] == true){ return ;}
    visited[x][y] = true;
    if(arr[x][y] == 0){
        width++;
        for(int i=0 ; i<4 ; i++){
            int adj_x = x+dir_x[i];
            int adj_y = y+dir_y[i];
            if( (0<=adj_x && adj_x<m) && (0<=adj_y && adj_y<n)){
                if(arr[adj_x][adj_y] == 0 && visited[adj_x][adj_y] == false){
                    DFS(adj_x , adj_y);
                }
            }
        }
    }
}

int main(){
    int k;
    cin >> m >> n >> k;

    for(int i=0 ; i<k ; i++){
        int x1,y1 ,x2,y2;
        cin >> x1>>y1>>x2>>y2;
        for(int j= y1; j<y2 ; j++){
            for(int l=x1 ; l<x2 ;l++){
                arr[j][l] = 1;
            }
        }
    }
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(arr[i][j] == 0 && visited[i][j] == false){
                width = 0;
                DFS(i,j);
                rel.push_back(width);
            }
        }
    }
    sort(rel.begin() , rel.end());
    cout << rel.size() << endl;
    for(auto it : rel){
        cout << it << " ";
    }
    return 0;
}