#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first * a.second) > (b.first * b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int testcase = 0 ; testcase < t ; testcase++){
        int answer = 0, temp = 0;
        vector<pair<int, int>> v;

        int j, n;
        cin >> j >> n;
        for(int i = 0 ; i < n ; i++){
            int r, c;
            cin >> r >> c;
            v.push_back({r, c});
        }

        sort(v.begin(), v.end(), comp);

        for(int i = 0 ; i < n ; i++){
            temp += v[i].first * v[i].second;
            if(temp >= j){
                answer = i + 1;
                break;
            }
        }

        cout << answer << '\n';
    }
    return 0;
}