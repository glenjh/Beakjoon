#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
vector<int> v;
set<vector<int>> s;
vector<int> nums;

void DFS(int cnt, int last){
    if(cnt == m){
        s.insert(nums);
        return;
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(nums.empty()){
            nums.push_back(v[i]);
            DFS(cnt + 1, last);
            nums.pop_back();
        }else{
            if(v[i] >= nums[nums.size() - 1]){
                nums.push_back(v[i]);
                DFS(cnt + 1, last);
                nums.pop_back();
            }
        }
    }
}

int main() {
    FastIO();

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    DFS(0, 0);

    for(auto it : s){
        for(auto num : it){
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}