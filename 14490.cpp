#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input , one, two;
    int pivot;
    cin >> input;
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == ':'){
            pivot = i;
        }
    }

    for(int i = 0 ; i < pivot ; i++){
        one += input[i];
    }

    for(int i = pivot+1 ; i < input.length() ; i++){
        two += input[i];
    }

    int i_one = stoi(one) , i_two = stoi(two);
    int arr[2] = {i_one , i_two};
    sort(arr, arr+2);

    int gcd;
    for(int i = arr[0] ; i >= 1 ; i--){
        if(arr[0] % i == 0 && arr[1]%i == 0){
            gcd = i;
            break;
        }
    }
    cout << i_one/gcd << ':' << i_two/gcd;
    return 0;
}