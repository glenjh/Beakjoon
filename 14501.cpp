#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v;
    int n, answer = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int day, money;
        cin >> day >> money;
        v.push_back({day, money});
    }

    for(int startDay = 0 ; startDay < n ; startDay++){
        cout << "start : " << startDay << '\n';
        int moneyCnt = v[startDay].second;
        int nextDay = startDay + v[startDay].first;
        
        if(nextDay >= n-1){ continue; }

        moneyCnt += v[nextDay].second;

        cout << "firstDay : " << nextDay << '\n';
        cout << "firstMoney : " << moneyCnt << '\n';

        while(nextDay <= n-1){
            if (nextDay < n - 1 && (nextDay + v[nextDay].first + v[nextDay + v[nextDay].first].first) <= n)
            {
                nextDay += v[nextDay].first;
                moneyCnt += v[nextDay].second;
            }
            else
            {
                break;
            }

            cout << "nextDay : " << nextDay << '\n';
            cout << "moneyCnt : " << moneyCnt << '\n';
            
        }

        cout << "****** day change**********" << '\n';
        if(moneyCnt >= answer){
            answer = moneyCnt;
        }
    }


    cout << answer << '\n';

    return 0;
}