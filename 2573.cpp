#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[301][301];
int howMuchMelt[301][301];
int dir[4] = {0, 1, 0, -1};

bool visited[301][301];

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void reset(){
    for(int i = 0 ; i < 301 ; i++){
        for(int j = 0 ; j < 301 ; j++){
            howMuchMelt[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void How(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] != 0){
                for(int k = 0 ; k < 4 ; k++){
                    int nx = i + dir[k];
                    int ny = j + dir[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m){ continue; }
                    if(arr[nx][ny] == 0){
                        howMuchMelt[i][j]++;
                    }
                }
            }
        }
    }
}

void melt(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(howMuchMelt[i][j] != 0){
                int leftOver = arr[i][j] - howMuchMelt[i][j];
                if(leftOver > 0){
                    arr[i][j] = leftOver;
                }
                else{ arr[i][j] = 0; }
            }
        }
    }
}

void print(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void BFS(int x, int y){

}

int main(){
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < 2 ; i++){
        reset();
        How();
        melt();
        print();
        cout << '\n';
    }

    return 0;
}