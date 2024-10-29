#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pair<string, int>> v;

string Search(int start, int end, int input){

    int mid;
    while(start <= end){
        mid = (start + end) / 2;

        if(v[mid].second < input){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return v[start].first;
}

int main() {
    FastIO();

    int n, m;
    cin >> n >> m;

    string init;
    for(int i = 0 ; i  < n ; i++){
        string rank;
        int input;
        cin >> rank >> input;
        v.push_back({rank, input});
    }

    for(int i = 0 ; i < m ; i++){
        int input;
        cin >> input;

        string ans = Search(0, v.size() - 1, input);
        cout << ans << '\n';
    }

    return 0;
}