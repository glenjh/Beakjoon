#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, a, b;
int ans = INT_MAX;
vector<int> v[11];
int peopleCnt[11];

bool visited[11];
bool selected[11];

void Reset(){
    for(int i = 1 ; i <= n ; i++){
        selected[i] = false;
    }
}

bool isConnected(vector<int> a, bool flag){ // 선택된 구역들이 모두 이어져 있는지
    Reset();

    queue<int> q;
    q.push(a[0]);
    selected[a[0]] = true;
    int cnt = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int nx = v[curr][i];
            if(!selected[nx] && visited[nx] == flag){
                selected[nx] = true;
                cnt += 1;
                q.push(nx);
            }
        }
    }

    if(cnt == a.size()){
        return true;
    }else{
        return false;
    }
}

bool isDividedWell(){ // 조건에 맞게 잘 나누어 졌는지
    vector<int> A, B;

    for(int i = 1 ; i <= n ; i++){
        if(visited[i]){ A.push_back(i); }
        else{ B.push_back(i); }
    }

    if(A.size() ==0 || B.size() == 0) { return false; } // 적어도 하나는 포함하는지
    if(!isConnected(A, true)){ return false; }
    if(!isConnected(B, false)){ return false; }
    return true;
}

void Divide(int idx, int depth){ // 지역들을 2개로 니눔
    if(isDividedWell()){
        for(int i = 1 ; i <= n ; i++){
            if(visited[i]){
                a += peopleCnt[i];
            }else{
                b += peopleCnt[i];
            }
        }
        ans = min(abs(a - b), ans);
        a = 0, b = 0;
    }

    for(int i = idx ; i <= n ; i++){
        if(!visited[i]){
            visited[i] = true;
            Divide(i, depth);
            visited[i] = false;
        }
    }
}

int main() {
    FastIO();

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> peopleCnt[i];
    }

    for(int i = 1 ; i <= n ; i++){
        int cnt;
        cin >> cnt;
        for(int j = 0 ; j < cnt ; j++){
            int neighbor;
            cin >> neighbor;
            v[i].push_back(neighbor);
            v[neighbor].push_back(i);
        }
    }

    Divide(1, 0);

    if(ans == INT_MAX){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }

    return 0;
}