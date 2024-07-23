#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int answer = 0;
bool visited[9];
vector<int> v;
vector<int> ans;
vector<int> lists;

void DFS(int depth, int n){
    if(depth == n){
        int temp = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            temp += abs(lists[i] - lists[i + 1]);
        }
        answer = max(answer, temp);

        return;
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            lists.push_back(v[i]);

            DFS(depth + 1, n);

            lists.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    FastIO();

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    DFS(0, n);

    cout << answer << '\n';

    return 0;
}