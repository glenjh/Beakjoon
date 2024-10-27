#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Room{
    string info = "Waiting!";
    int initLevel;
    vector<pair<int, string>> players;
};

bool comp(pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
}

int main() {
    FastIO();

    vector<Room> rooms(300);
    int p, m, cnt = 0;
    cin >> p >> m;

    for(int i = 0 ; i < p ; i++){
        int l, idx = 0;
        string n;
        cin >> l >> n;

        while(true){
            if (rooms[idx].players.size() < m){
                if(rooms[idx].players.empty()){
                    cnt += 1;
                    rooms[idx].initLevel = l;
                    rooms[idx].players.push_back({l, n});

                    if(rooms[idx].players.size() == m){
                        rooms[idx].info = "Started!";
                    }
                    break;
                }
                else{
                    if (rooms[idx].initLevel - 10 <= l && 
                        l <= rooms[idx].initLevel + 10)
                    {
                        rooms[idx].players.push_back({l, n});
                        if (rooms[idx].players.size() == m){
                            rooms[idx].info = "Started!";
                        }
                        break;
                    }
                }
            }
            else{
                rooms[idx].info = "Started!";
            }

            idx++;
        }
    }

    for(int i = 0 ; i < cnt ; i++){
        cout << rooms[i].info << '\n';

        sort(rooms[i].players.begin(), rooms[i].players.end(), comp);
        for(auto it : rooms[i].players){
            cout << it.first << ' ' << it.second << '\n';
        }
    }

    return 0;
}