#include <iostream>
#include <stack>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[100001];
int visibleCnt[100001];
int nearest[100001];

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    stack<pair<int, int>> rightSight, leftSight;


    // 오른쪽으로 보면 어떻게 되는지
    for(int i = n ; i >= 1 ; i--){
        while(!rightSight.empty() && rightSight.top().second <= arr[i]){
            rightSight.pop();
        }
        visibleCnt[i] += rightSight.size();

        if(!rightSight.empty()){
            nearest[i] = rightSight.top().first;
        }

        rightSight.push({i, arr[i]});
    }

    // 왼쪽으로 보면 어떻게 되는지
    for(int i = 1 ; i <= n ; i++){
        while(!leftSight.empty() && leftSight.top().second <= arr[i]){
            leftSight.pop();
        }
        visibleCnt[i] += leftSight.size();

        if(!leftSight.empty()){
            if(nearest[i] != 0){
                if(abs(i - nearest[i]) >= abs(i - leftSight.top().first)){
                    nearest[i] = leftSight.top().first;
                }
            }
            else{
                nearest[i] = leftSight.top().first;
            }
        }

        leftSight.push({i, arr[i]});
    }

    for(int i = 1 ; i <= n ; i++){
        if(visibleCnt[i] != 0){
            cout << visibleCnt[i] << ' ' << nearest[i] << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }

    return 0;
}