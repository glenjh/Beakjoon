#include <iostream>
#include <vector>
using namespace std;

int main(){
    int student_num, number;
    vector<int> v;
    cin >> student_num;
    for(int i=0; i<student_num ; i++){
        cin >> number;
        v.insert(v.end()-number,i+1);
    }
    for(auto it : v){
        cout << it << ' ';
    }
    return 0;
}