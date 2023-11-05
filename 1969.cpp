#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    string answer = "";
    cin >> n >> m;

    string **DNA_list = new string*[n];
    for(int i = 0 ; i < n ; i++){
        DNA_list[i] = new string[m];
    }
    string *for_comp = new string[n];
    
    for(int i = 0 ; i < n ; i++){
        string DNA;
        cin >> DNA;
        for(int j = 0 ; j < DNA.length() ; j++){
            DNA_list[i][j] = DNA[j];
        }
        for_comp[i] = DNA;
    }

    for(int i = 0 ; i < m ; i++){
        int cnt[4] = {0, 0, 0, 0}; // A, C, G, T
        int temp;
        for(int j = 0 ; j < n ; j++){
            if(DNA_list[j][i] == "A"){ cnt[0] += 1; }
            else if(DNA_list[j][i] == "C"){ cnt[1] += 1; }
            else if(DNA_list[j][i] == "G"){ cnt[2] += 1; }
            else if(DNA_list[j][i] == "T"){ cnt[3] += 1; }
        }

        int most_common = *max_element(cnt, cnt+4);
        for(int j = 0 ; j < 4 ; j++){
            if(cnt[j] == most_common){
                temp = j;
                break;
            }
        }
        if(temp == 0){ answer += "A"; }
        else if(temp == 1){ answer += "C"; }
        else if(temp == 2){ answer += "G"; }
        else if(temp == 3){ answer += "T"; }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(answer[j] != for_comp[i][j]){
                cnt += 1;
            }
        }
    }

    cout << answer << '\n';
    cout << cnt << '\n';
    return 0;
}