#include <iostream>
#include <queue>

using namespace std;

int n, k, t = 0, fastest_time;

bool visited[100001];

void BFS(int x, int cnt){
    queue<pair<int,int>> q;
    q.push({x, cnt});

    while(!q.empty()){
        int curr = q.front().first;
        int how_many = q.front().second;
        q.pop();
        visited[curr] = true;

        if(curr == k){
            if(t == 0){
                fastest_time = how_many;
                t++;
            }else if(t > 0 && fastest_time == how_many){
                    t++;
            }
        }

        int next_do[3] = {curr - 1 , curr + 1, curr * 2};
        for(int i = 0 ; i < 3 ; i++){
            int next = next_do[i];
            if(next < 0 || next > 100000){ continue; }
            if(!visited[next]){
                q.push({next, how_many+1});
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    BFS(n, 0);

    cout << fastest_time << '\n' << t << '\n';

    return 0;
}