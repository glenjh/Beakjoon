#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    FastIO();

    int s, p, answer = 0;
    int arr[4]; // A, C, G, T
    int chk[4];
    string dna;

    cin >> s >> p;
    cin >> dna;
    for(int i = 0 ; i < 4 ; i++){
        cin >> arr[i];
        chk[i] = 0;
    }
    

    for(int i = 0 ; i < p ; i++){
        char c = dna[i];

        if(c == 'A'){
            chk[0] += 1;
        }
        else if (c == 'C'){
            chk[1] += 1;
        }
        else if (c == 'G') {
            chk[2] += 1;
        }
        else if (c == 'T'){
            chk[3] += 1;
        }
    }

    bool flag = true;
    for(int i = 0 ; i < 4 ; i++){
        if(chk[i] < arr[i]){
            flag = false;
            break;
        }
    }
    if(flag){ answer += 1; }

    int left = 0, right = p;
    while(right < s){
        char sub = dna[left];
        if (sub == 'A'){
            chk[0] -= 1;
        }
        else if (sub == 'C'){
            chk[1] -= 1;
        }
        else if (sub == 'G'){
            chk[2] -= 1;
        }
        else if (sub == 'T'){
            chk[3] -= 1;
        }

        char add = dna[right];
        if (add == 'A' ){
            chk[0] += 1;
        }
        else if (add == 'C' ){
            chk[1] += 1;
        }
        else if (add == 'G' ){
            chk[2] += 1;
        }
        else if (add == 'T' ){
            chk[3] += 1;
        }

        bool flag = true;
        for (int i = 0; i < 4; i++){
            if (chk[i] < arr[i]){
                flag = false;
                break;
            }
        }
        if (flag) { answer += 1; }

        left += 1;
        right += 1;
    }

    cout << answer << '\n';

    return 0;
}