#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int n, m, answer = 0;
    vector<int> v;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int start = 0, end = n - 1;

    while(start < end){
        int sum = v[start] + v[end];
        if(sum == m){
            answer += 1;
            start++;
            end--;
        }
        else{
            if(sum > m){
                end--;
            }
            else if(sum < m){
                start++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}