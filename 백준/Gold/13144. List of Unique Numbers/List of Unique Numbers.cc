#include <iostream>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
ll ans;
int arr[100001];

bool visited[100001];

int main() {
    FastIO();

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int l, r = 0;
    for(l = 0 ; l < n ; l++){
        while(r < n){
            if(!visited[arr[r]]){
                visited[arr[r]] = true;
                r++;
            }
            else{
                break;
            }
        }
        ans += r - l;
        visited[arr[l]] = false;
    }

    cout << ans << '\n';

    return 0;
}