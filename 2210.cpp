#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;

string arr[5][5];

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

void DFS(int x, int y, string temp, int cnt){
    if(cnt == 6){ 
        s.insert(temp);
        return; 
    }

    for(int i = 0 ; i < 4 ; i++){
        int x_move = x + dir_x[i];
        int y_move = y + dir_y[i];

        if(x_move < 0 || y_move < 0 || x_move >= 5 || y_move >= 5){ continue; }
        string a = temp;
        a += arr[x_move][y_move];
        DFS(x_move, y_move, a ,cnt+1);
    }
}

int main(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j <5 ; j++){
            string one = arr[i][j];
            DFS(i, j, one, 1);
        }
    }

    cout << s.size();

    return 0;
}