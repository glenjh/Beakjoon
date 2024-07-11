#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int sushi[3001]; // 각 초밥이 몇개 있는지
int origin[3001];
bool eatten[3001]; // 몇번째 초밥을 먹었는지

int main() {
    FastIO();

    vector<int> v;
    vector<int> v2;
    int n, d, k, c, answer = 0;
    cin >> n >> d >> k >> c;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
        v2.push_back(input);
        sushi[input] += 1;
        origin[input] += 1;
    }

    for(auto it : v2){
        v.push_back(it);
    }

    bool free = false;
    int l = 0, r = k, cnt = 0;
    for(int i = 0 ; i < k ; i++){
        if(!eatten[v[i]]){
            eatten[v[i]] = true;
            cnt += 1;
        }
        sushi[v[i]] -= 1;
    }
    
    if(!eatten[c]){
        free = true;
        cnt += 1;
    }
    answer = max(answer, cnt);

    while(l < n){
        if(free){
            cnt -= 1;
            free = false;
        }

        sushi[v[l]] += 1;
        if( eatten[v[l]] && (sushi[v[l]] == origin[v[l]]) ){
            eatten[v[l]] = false;
            cnt -= 1;
        }

        
        if(!eatten[v[r]]){
            eatten[v[r]] = true;
            cnt += 1;
        }
        sushi[v[r]] -= 1;

        if(!eatten[c]){
            free = true;
            cnt += 1;
        }
        answer = max(answer, cnt);

        l += 1;
        r += 1;
    }

    cout << answer << '\n';

    return 0;
}