#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char w_start[8][8] = {
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    };

char b_start[8][8] = {
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    };

            

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, diff_cnt, r_diff_cnt;
    vector<int> v;
    cin >> n >> m;

    char **arr = new char *[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = new char[m];
    }

    for(int i = 0 ; i < n ; i++){
        string line;
        cin >> line;
        for(int j = 0 ; j < line.length() ; j++){
            arr[i][j] = line[j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int r_i = i + 7, r_j = j + 7;
            int w_diff_cnt = 0, b_diff_cnt = 0;
            if(i+7 >= n || j+7 >= m){ continue; }

            for(int a = 0 ; a < 8 ; a++){
                    for(int b = 0 ; b < 8 ; b++){
                        if(w_start[a][b] != arr[i+a][j+b]){
                            w_diff_cnt++;
                        }
                        if(b_start[a][b] != arr[i+a][j+b]){
                            b_diff_cnt++;
                        }
                    }
                }
                if(b_diff_cnt > w_diff_cnt){ v.push_back(w_diff_cnt); }
                else{ v.push_back(b_diff_cnt); }
        }
    }
    sort(v.begin() , v.end());

    cout << v[0];
    return 0;
}