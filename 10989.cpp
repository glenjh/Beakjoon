#include <iostream>
using namespace std;

int arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int testcase, input, max = 0;
    cin >> testcase;
    for(int i=0 ; i<testcase ; i++){
        cin >> input;
        if(input > max) { max = input; }
        arr[input]+=1;
    }
    for(int i=0 ; i<=max ; i++){
        for(int j=0 ; j<arr[i] ; j++){
            cout << i << '\n';
        }
    }
    return 0;
}
