#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool visited[11];
int arr[11];

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        int input;
        cin >> input;

        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(input == 0 && arr[j] == 0){
                arr[j] = i;
                break;
            }
            
            if(arr[j] == 0){
                input--;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}