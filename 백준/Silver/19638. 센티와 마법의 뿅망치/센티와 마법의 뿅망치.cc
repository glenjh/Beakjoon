#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, h, t, cnt = 0;
    priority_queue<int> pq;

    cin >> n >> h >> t;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        pq.push(input);
    }

    bool flag = true;
    int remainTall = 1;

    if(pq.top() < h){
        cout << "YES" << '\n' << 0 << '\n';
        return 0;
    }

    while(!pq.empty()){
        int curr = pq.top(), temp = 0;
        pq.pop();

        if(curr == 1 && h == 1){
            flag = false;
            break;
        }

        if(curr < h){
            remainTall = curr;
            flag = true;
            break;
        }
        else{
            if(cnt < t){
                cnt += 1;
                curr /= 2;
                pq.push(curr);
            }
            else{
                flag = false;
                remainTall = curr;
                break;
            }
        }
    }

    if(flag){
        cout << "YES" << '\n' << cnt << '\n';
    }
    else{
        cout << "NO" << '\n' << remainTall << '\n';
    }

    return 0;
}