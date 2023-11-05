#include <iostream>
using namespace std;

const int INF = 100000000;
bool visited[1001] = {false,};
int dist[1001] = {0,};
int each_cost[1001][1001];
int where_i_start , where_i_end;

int min_cost(){
    int min = INF;
    int min_idx = 0;
    for(int i=0 ; i<1001 ; i++){
        if(dist[i] < min && visited[i] == false){
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}


void Dijkstra(int start_point){  
    for(int i=0 ; i<1001 ; i++){
        dist[i] = each_cost[start_point][i];
    }
    visited[start_point] = true;
    for(int i=0 ; i<999 ; i++){
        int curr = min_cost();
        visited[curr] = true;
        for(int j=0 ; j<1001 ; j++){
            if(dist[j] > dist[curr] + each_cost[curr][j]){
                dist[j] = dist[curr] + each_cost[curr][j];
            }
        }
    }
}


int main(){
    for(int i=0 ; i<1001 ; i++){
        each_cost[i][i] = 0; //자기자신
        for(int j=0 ; j<1001 ; j++){
            each_cost[i][j] = INF;
        }
    }
    int n , m , cost;
    int city_start , city_end;
    
    cin >>n;
    cin >>m;

    for(int i=0 ; i<m ; i++){
        cin >> city_start >> city_end >> cost;
        if(cost < each_cost[city_start][city_end]){
            each_cost[city_start][city_end] = cost;
        }
    }

    cin >> where_i_start >> where_i_end;
    Dijkstra(where_i_start);
    cout << dist[where_i_end];

    return 0;
}