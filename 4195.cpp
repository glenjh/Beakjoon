#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int p[2000000];
int how_many[2000000];

int find(int a){
    if(p[a] == a){ return a;}
    else{  
        p[a] = find(p[a]);
        return p[a];
    }
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        p[pb] = pa;
        how_many[pa] += how_many[pb];
        how_many[pb] = how_many[pa];
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testcase;
    cin >> testcase;
    for(int i=0 ; i<testcase ; i++){
        unordered_map<string,int> friend_network;
        int friend_num , id = 0;
        string friend_p , friend_c;
        cin >> friend_num;

        for(int j=0 ; j<2000000 ; j++){
            p[j] = j;
            how_many[j] = 1;
        }

        for(int j=0 ; j<friend_num ; j++){
            cin >> friend_p >> friend_c;

            if(friend_network.find(friend_p) == friend_network.end()){
                friend_network.insert(pair<string,int>(friend_p,id++));
            }
            if(friend_network.find(friend_c) == friend_network.end()){
                friend_network.insert(pair<string,int>(friend_c,id++));
            }

            uni(friend_network[friend_p] , friend_network[friend_c]);
            int idx = find(friend_network[friend_p]);
            cout << how_many[idx] << '\n';
        }
    }
    return 0;
}