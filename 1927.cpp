#include <iostream>
#include <queue>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

   int t;
   cin >> t;
   priority_queue<int , vector<int> , greater<int>> pq;
   for(int i=0 ; i<t ; i++){
       int input;
       
       cin >> input;

       if(input == 0){
           if(pq.empty() == true){ cout << 0 << '\n'; }
           else{ 
               cout << pq.top() << '\n'; 
               pq.pop();
            }
       }else{ pq.push(input); }
   }
    return 0;
}