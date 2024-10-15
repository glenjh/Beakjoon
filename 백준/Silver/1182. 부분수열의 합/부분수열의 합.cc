#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, s, sum, ans;
int arr[21];

bool visited[21];

void Sol(int cnt, int target, int idx){
    int sum = 0;
    if(cnt == target){
        for(int i = 1 ; i <= n ; i++){
            if(visited[i]){
                sum += arr[i];
            }
        }
        
        if(sum == s){
            ans += 1;
        }

        return;
    }

    for(int i = idx ; i <= n ; i++){
        if(!visited[i]){
            visited[i] = true;

            Sol(cnt + 1, target, i);

            visited[i] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    for(int i = 1 ; i <= n ; i++){
        Sol(0, i, 1);
    }

    cout << ans << '\n';

    return 0;
}