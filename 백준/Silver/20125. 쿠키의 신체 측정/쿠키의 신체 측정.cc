#include <iostream>
#include <string>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

char arr[1001][1001];

int main() {
    FastIO();

    int headX, headY;
    int heartX, heartY, leftArmLen = 0, rightArmLen = 0, wirstLen = 0, leftLegLen = 0, rightLegLen = 0;

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < input.length() ; j++){
            arr[i][j + 1] = input[j];
        }
    }

    bool found = false;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(arr[i][j] == '*' && !found){
                headX = i;
                headY = j;
                found = true;
            }
        }
    }

    heartX = headX + 1;
    heartY = headY;

    // left arm
    for(int i = heartY - 1 ; i >= 1 ; i--){
        if(arr[heartX][i] == '*'){
            leftArmLen += 1;
        }else{ break; }
    }

    //right arm
    for(int i = heartY + 1 ; i <= n ; i++){
        if(arr[heartX][i] == '*'){
            rightArmLen += 1;
        }else{ break; }
    }

    //wrist 
    int anchorX, anchorY = heartY;
    for(int i = heartX + 1 ; i <= n ; i++){
        if(arr[i][heartY] == '*'){
            anchorX = i;
            wirstLen += 1;
        }
    }

    //left leg
    for(int i = anchorX + 1 ; i <= n ; i++){
        if(arr[i][anchorY - 1] == '*'){
            leftLegLen += 1;
        }else{ break; }
    }

    //right leg
    for(int i = anchorX + 1 ; i <= n ; i++){
        if(arr[i][anchorY + 1] == '*'){
            rightLegLen += 1;
        }else{ break; }
    }

    cout << heartX << ' ' << heartY << '\n';
    cout << leftArmLen << ' ' << rightArmLen << ' ' << wirstLen << ' ' << leftLegLen << ' ' << rightLegLen << '\n';

    return 0;
}