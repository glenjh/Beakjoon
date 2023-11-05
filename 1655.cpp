#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int n, number;
    // priority_queue<int ,vector<int>, greater<int>> my_queue;
    // priority_queue<int> for_store;
    // cin >> n;

    // for(int i = 0 ; i < n ; i++){
    //     cin >> number;
    //     my_queue.push(number);
    //     int len = my_queue.size();

    //     if(len % 2 == 1){
    //         for(int j = 0 ; j < (len/2) ; j++){
    //             for_store.push(my_queue.top());
    //             my_queue.pop();
    //         }
    //     }
    //     else{
    //         for(int j = 0 ; j < (len/2) - 1 ; j++){
    //             for_store.push(my_queue.top());
    //             my_queue.pop();
    //         }
    //     }
    //     cout << my_queue.top() << '\n';
    //     while(!for_store.empty()){
    //         my_queue.push(for_store.top());
    //         for_store.pop();
    //     }
    // }

    int n, number;
    priority_queue<int, vewtor<int>, greater<int>> small;
    priority_queue<int> big;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> number;
        if(small.empty()){
            small.push(number);
        }
        else if(big.empty()){
            big.push(number);
        }
        else if(small.size() == big.size()){
            if(number > small.top()){
                
            }else{

            }
        }
    }
    return 0;
}