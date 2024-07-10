#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int t;
    cin >> t;

    for(int teseCase = 0 ; teseCase < t ; teseCase++){
        vector<int> v(26);
        string w;
        int k, m = 0, M = 0;

        cin >> w;
        for(int i = 0 ; i < w.length() ; i++){
            v[w[i] - 'a'] += 1;
        }
        cin >> k;

        for(int i = 0 ; i < w.length() ; i++){
            if (v[w[i] - 'a'] >= k){
                int cnt = 0;
                for(int j = i ; j < w.length() ; j++){
                    if(w[i] == w[j]){
                        cnt += 1;

                        if(cnt == k){
                            if(m == 0){
                                m = j - i + 1;
                                M = m;
                            }
                            else{
                                m = min(m, j - i + 1);
                                M = max(M, j - i + 1);
                            }
                            break;
                        }
                    }

                }
            }
        }

        if(m == 0){
            cout << -1 << '\n';
        }else{
            cout << m << ' ' << M << '\n';
        }
    }

    return 0;
}