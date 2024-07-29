#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define ll long long int

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    ll n, m, k;
    vector<pair<ll, ll>> beers;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> n >> m >> k;
    for(int i = 0 ; i < k ; i++){
        int v, c;
        cin >> v >> c;
        beers.push_back({c, v}); // 도수, 선호도
    }
    sort(beers.begin(), beers.end());

    ll preferenceSum = 0, answer = -1;
    for(int i = 0 ; i < k ; i++){
        pq.push(beers[i].second);
        preferenceSum += beers[i].second;

        if(pq.size() > n){
            preferenceSum -= pq.top();
            pq.pop();
        }

        if(pq.size() == n && preferenceSum >= m){
            answer = beers[i].first;
            break;
        }
    }   

    cout << answer << '\n';

    return 0;
}