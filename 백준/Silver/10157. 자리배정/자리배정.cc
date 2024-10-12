#include <iostream>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int c, r, k;
    cin >> c >> r >> k;

    if(c * r < k){
        cout << 0 << '\n';
    }
    else{
        int h = r, w = c, x = 1, y = 0;

        int sign = 1;
        while(k > 0){
            for(int i = 0 ; i < h ; i++){
                if(k > 0){
                    y += 1 * sign;
                    k--;
                }
            }
            w--;

            for(int i = 0 ; i < w ; i++){
                if(k > 0){
                    k--;
                    x += 1 * sign;
                }
            }
            h--;
            sign *= -1;
        }

        cout << x << ' ' << y << '\n';
    }


    

    return 0;
}