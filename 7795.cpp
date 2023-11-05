#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int testcase = 0; testcase < t; testcase++){
        int n, m, cnt = 0;
        cin >> n >> m;
        vector<int> a;
        vector<int> b;

        for (int i = 0; i < n; i++){
            int input;
            cin >> input;
            a.push_back(input);
        }

        for (int i = 0; i < m; i++){
            int input;
            cin >> input;
            b.push_back(input);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int aRight = a.size() - 1, bRight = b.size() - 1;

        while(aRight >=0 && bRight >= 0){
            if(a[aRight] > b[bRight]){
                cnt++;
                aRight--;
            }
        }
        
        cout << cnt << '\n';
    }
    return 0;
}