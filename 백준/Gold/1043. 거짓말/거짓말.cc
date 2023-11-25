#include <iostream>
#include <set>
#include <vector>
#define MAX 51

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int p[MAX];
set<int> secret;

int My_Find(int a){
    if(p[a] == a){ return a; }
    return p[a] = My_Find(p[a]);
}

void My_Uni(int a, int b){
    int pa = My_Find(a);
    int pb = My_Find(b);

    if(pa == pb){ return; }

    if(secret.find(pa) != secret.end()){
        p[pb] = pa; 
    }
    else{
        p[pa] = pb;
    }
}


int main() {
    FastIO();

    int n, m;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
    }

    int a;
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        int input;
        cin >> input;
        secret.insert(input);
    }
    
    vector<int> v[MAX];
    for(int i = 0 ; i < m ; i++){
        int cnt;
        cin >> cnt;
        for(int j = 0 ; j < cnt ; j++){
            int input;
            cin >> input;
            v[i].push_back(input);
        }
    }

    for(int i = 0 ; i < m ; i++){
        if(v[i].size() == 1){ continue; }
        for(int j = 0 ; j < v[i].size() - 1 ; j++){
            My_Uni(v[i][j], v[i][j + 1]);
        }
    }

    int answer = m;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < v[i].size(); j++){
            if( secret.find(My_Find(v[i][j])) != secret.end() ){
                answer--;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}