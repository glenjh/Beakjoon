#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int testcase = 0 ;testcase < t ; testcase++){
        vector<pair<int, int>> v;
        int n, answer = 1;
        cin >> n;

        for(int i = 0 ; i < n ; i++){
            int grade1, grade2;
            cin >> grade1 >> grade2;
            v.push_back({grade1, grade2});
        }

        sort(v.begin(), v.end());

        int Fst = 0;
        
        for(int i = 1 ; i < n ; i++){
            if(v[i].second < v[Fst].second){
                answer++;
                Fst = i;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}