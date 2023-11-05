#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(int a, int b){
    return a > b;
}

int main(){
    int b, c, d, before = 0, after = 0;
    vector<int> burger;
    vector<int> side;
    vector<int> drink;

    cin >> b >> c >> d;

    int mm = min(b, c);
    int m = min(mm, d);

    for(int i = 0 ; i < b ; i++){
        int input; 
        cin >> input;
        before += input;
        burger.push_back(input);
    }

    for(int i = 0 ; i < c ; i++){
        int input;
        cin >> input;
        before += input;
        side.push_back(input);
    }

    for(int i = 0 ; i < d ; i++){
        int input;
        cin >> input;
        before += input;
        drink.push_back(input);
    }

    sort(burger.begin(), burger.end(), comp);
    sort(side.begin(), side.end(), comp);
    sort(drink.begin(), drink.end(), comp);

    for(int i = 0 ; i < m ; i++){
        after += burger[i] * 0.9;
        after += side[i] * 0.9;
        after += drink[i] * 0.9;
    }

    for(int i = m ; i < burger.size() ; i++){
        after += burger[i];
    }

    for (int i = m; i < side.size(); i++){
        after += side[i];
    }

    for (int i = m; i < drink.size(); i++){
        after += drink[i];
    }

    cout << before << '\n';
    cout << after << '\n';

    return 0;
}
    
    