#include <iostream>
#include <queue>

using namespace std;

int s, t, answer;

void BFS(int x, int y, int cnt){
    queue< pair<pair<int, int>, int> > q;
    q.push({{x, y}, 0});

    while(!q.empty()){
        int curr_point = q.front().first.first;
        int curr_you_point = q.front().first.second;
        int curr_cnt = q.front().second;
        q.pop();

        if(curr_point > curr_you_point){ continue; }
        if(curr_point == curr_you_point){
            if(answer == 0){
                answer = curr_cnt;
            }else{
                answer = min(answer, curr_cnt);
            }
        }

        q.push({{curr_point * 2, curr_you_point + 3} , curr_cnt + 1});
        q.push({{curr_point + 1, curr_you_point} , curr_cnt + 1});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    for(int i = 0 ; i < c ; i++){
        cin >> s >> t;
        BFS(s, t, 0);
        cout << answer << '\n';
        answer = 0;
    }

    return 0;
}