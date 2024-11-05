#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, x, y;
int startX, startY, endX, endY;
vector<pair<int, int>> shops;

bool visited[101];
bool flag = false;

void BFS(int x, int y, int beer, int moved){
    for(int i = 0 ; i < 101 ; i++){
        visited[i] = false;
    }

    queue< pair< pair<int, int>, pair<int, int> > > q;
    q.push({ {x, y}, {20, moved} });

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cBeer = q.front().second.first;
        int cMoved = q.front().second.second;
        q.pop();

        int distance = abs(cx - endX) + abs(cy - endY);
        if(distance <= cBeer * 50){
            flag = true;
            return;
        }

        for (int i = 0; i < shops.size() ; i++){
            if(!visited[i]){
                int d = abs(cx - shops[i].first) + abs(cy - shops[i].second);
                if(d <= cBeer * 50){
                    visited[i] = true;
                    q.push({{shops[i].first, shops[i].second}, {20, moved}});
                }
            }
        }
    }
}

int main() {
    FastIO();

    int testCase;
    cin >> testCase;

    for(int t = 0 ; t < testCase ; t++){
        shops.clear();
        flag = false;

        cin >> n;
        cin >> startX >> startY;

        for(int i = 0 ; i < n ; i++){
            int shopX, shopY;
            cin >> shopX >> shopY;
            shops.push_back({shopX, shopY});
        }

        cin >> endX >> endY;

        BFS(startX, startY, 20, 0);

        if(flag){
            cout << "happy" << '\n';
        }
        else{
            cout << "sad" << '\n';
        }
    }

    return 0;
}