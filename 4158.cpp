#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<int, int> CD;

    while(true){
        
        int n, m, answer = 0;
        cin >> n >> m;
        if(m == 0 && n == 0){ break; }

        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            CD[input] += 1;
        }

        for (int i = 0; i < m; i++)
        {
            int input;
            cin >> input;
            if (CD[input] != 0)
            {
                answer += 1;
            }
        }

        cout << answer << '\n';
        CD.clear();
    }
    return 0;
}