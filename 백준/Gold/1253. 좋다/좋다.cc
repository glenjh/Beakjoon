// #include <iostream>
// #include <algorithm>

// using namespace std;

// void FastIO(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// }

// int main() {
//     FastIO();

//     int n, answer = 0;
//     int arr[2000];

//     cin >> n;
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr[i];
//     }
//     sort(arr, arr + n);

//     for(int i = 0 ; i < n ; i++){
//         int l = 0, r = n - 1, target;
//         while(l < r){
//             target = arr[i];

//             if(arr[l] + arr[r] == target){
//                 if(l != i && r != i){
//                     answer += 1;
//                     break;
//                 }
//                 else if(l == i){
//                     l++;
//                 }
//                 else if(r == i){
//                     r++;
//                 }
//             }
//             else{
//                 if(arr[l] + arr[r] > target){
//                     r -= 1;
//                 }
//                 else if(arr[l] + arr[r] < target){
//                     l += 1;
//                 }
//             }
//         }
//     }

//     cout << answer << '\n';

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[2000];

int main()
{
    int num, result = 0, val;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr, arr + num);

    for (int i = 0; i < num; i++)
    {
        val = arr[i]; // 찾고자 하는 번호
        int l = 0, r = num - 1, sum;
        while (l < r)
        {
            sum = arr[l] + arr[r];
            if (sum == val)
            {
                if (l != i && r != i)
                {
                    result++;
                    break;
                }
                else if (l == i)
                    l++;
                else if (r == i)
                    r--;
            }
            else if (sum < val)
                l++;
            else
                r--;
        }
    }
    cout << result;
    return 0;
}