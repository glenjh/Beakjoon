#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, s, e, answer,tel_pos;
vector<int> v[300001];
int dir[2] = {-1, 1};

bool visited[300001];

void BFS(int x, int cnt){
    queue<pair<int, int>> q;
    q.push({x, cnt});
    visited[x] = true;

    while(!q.empty()){
        int curr_pos = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        if(curr_pos == e || tel_pos == e){
            if(answer == 0){
                answer = curr_cnt;
            }else{
                answer = min(answer, curr_cnt);
            }
        }

        if((1 <= curr_pos -1 && curr_pos - 1 <= n) && !visited[curr_pos - 1]){
            q.push({curr_pos - 1, curr_cnt + 1});
            visited[curr_pos - 1] = true;
        }

        if ((1 <= curr_pos + 1 && curr_pos + 1 <= n) && !visited[curr_pos + 1]){
            q.push({curr_pos + 1, curr_cnt + 1});
            visited[curr_pos + 1] = true;
        }

        for(int i = 0 ; i < v[curr_pos].size() ; i++){
            int tel_pos = v[curr_pos][i];
            if(!visited[tel_pos]){
                q.push({tel_pos, curr_cnt + 1});
                visited[tel_pos] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s >> e;

    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    BFS(s, 0);
    
    cout << answer << '\n';

    return 0;
}