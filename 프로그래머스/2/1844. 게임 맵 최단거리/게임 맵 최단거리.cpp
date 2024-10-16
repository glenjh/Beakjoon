#include <vector>
#include <queue>
using namespace std;

int arr[101][101];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

bool visited[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int x = maps[0].size(), y = maps.size();
    
    queue< pair<int, int> > q;
    arr[0][0] = 1;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if(cx == x - 1 && cy == y - 1){
            answer = arr[cy][cx];
            return answer;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];
            if(nx < 0 || ny < 0 || nx >= x || ny >= y){ continue; }
            if(!visited[ny][nx] && maps[ny][nx] == 1){
                visited[ny][nx] = true;
                arr[ny][nx] = arr[cy][cx] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    answer = -1;
    
    
    return answer;
}