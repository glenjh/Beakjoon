#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int testcase = 0 ; testcase < t ; testcase++){
        int n, m, cnt = 0;
        cin >> n >> m;
        for(int i = n ; i<= m ; i++){
            string num = to_string(i);
            for(int j = 0 ; j < num.length() ; j++){
                if(num[j] == '0'){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}