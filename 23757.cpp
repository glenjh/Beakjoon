#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    priority_queue<int> q;

    bool flag = true;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int num_of_presents;
        cin >> num_of_presents;
        q.push(num_of_presents);
    }

    long long temp = 0;
    for(int i = 0 ; i < m ; i++){
        int hope_num;
        cin >> hope_num;

        int most_many = q.top();
        q.pop();

        int after_taken = most_many - hope_num;
        if(after_taken >= 0){
            q.push(after_taken);
        }else{
            flag = false;
            break;
        }
    }

    if(!flag){ cout << 0; }
    else { cout << 1; }

    return 0;
}