#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FastIO();

    int n, m;
    cin >> n >> m;
    int arr[52][52];

    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j] = input[j] - '0';
        }
    }

    int answer = 1, w, h;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            for(int k = j+1 ; k < m ; k++){
                if(arr[i][j] == arr[i][k]){
                    w = abs(k - j);
                    if(i+w >= n || j+w >= m){ continue; }
                    if(arr[i+w][j] == arr[i][j] && arr[i+w][j] == arr[i+w][j+w]){ 
                        answer = max(answer, (w+1) * (w+1));
                    }
                }
            }
        }
    }

    cout << answer << '\n';
    return 0;
}