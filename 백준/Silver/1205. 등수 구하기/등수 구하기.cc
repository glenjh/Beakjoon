#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main() {
    FastIO();

    int arr[100];
    int n, score, p;    
    cin >> n >> score >> p;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int rank = 1, count = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > score){
            rank++;
        }
        else if(arr[i] == score){
            rank = rank;
        }
        else{
            break;
        }
        count++;
    }

    if(count >= p){
        cout << -1 << '\n';
        return 0;
    }

    cout << rank << '\n';


    return 0;
}