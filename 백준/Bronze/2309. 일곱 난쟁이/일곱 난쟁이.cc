#include<iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    vector<int> arr(9);
    int sum = 0;
    int diff;

    int no_1;
    int no_2;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    diff = sum - 100;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j <9; j++) {
            if (arr[i] + arr[j] == diff) {
                no_1 = i;
                no_2 = j;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != no_1 && i != no_2) {
            cout << arr[i]<<endl;
        }
    }



    return 0;
}