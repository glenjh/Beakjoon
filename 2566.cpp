#include <iostream>

using namespace std;

int main(){
    int max = 0, m_i, m_j;

    for(int i = 1; i < 10 ; i++){
        for(int j = 1; j < 10 ; j++){
            int input;
            cin >> input;
            if(input >= max){
                max = input;
                m_i = i;
                m_j = j;
            }
        }
    }

    cout << max << '\n';
    cout << m_i << " " << m_j;
    return 0;
}